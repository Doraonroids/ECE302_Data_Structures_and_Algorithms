#include <string>
#include <vector>
#include <iostream>
#include <locale> 
#include "FindPalindrome.hpp"

using namespace std;

//------------------- HELPER FUNCTIONS -----------------------------------------

// non-class helper functions go here, should be declared as "static" so that
// their scope is limited

// helper function to convert string to lower case
static void convertToLowerCase(string & value)
{
	locale loc;
	for (unsigned int i=0; i<value.size(); i++) {
		value[i] = tolower(value[i],loc);
	}
}


//------------------- PRIVATE CLASS METHODS ------------------------------------
string FindPalindrome::tostring(vector<string> vec) const{
	string newstring = "";
	for(unsigned int i = 0; i < vec.size(); i++){
		newstring += vec[i];
	}
	return newstring;
}
bool FindPalindrome::exist(string s) const{
	/*
	int start = 0, end = vectorList.size() - 1;
	convertToLowerCase(s);
	
	while (start <= end) {
		int middle = start + (end - start) / 2;
		string temp = vectorList.at(middle);
		convertToLowerCase(temp);
		if (s == temp)
			return true;
		if (s > (vectorList[middle])){
			start = middle + 1;
		}else{
			end = middle - 1;
		}
	}
	return false;*/
	string temp = "";
	convertToLowerCase(s);
	for(unsigned int i = 0; i < vectorList.size(); i++){
		temp = vectorList.at(i);
		convertToLowerCase(temp);
		if(temp == s){
			return true;
		}
	}
	return false;
}


// private recursive function. Must use this signature!
void FindPalindrome::recursiveFindPalindromes(vector<string>
        candidateStringVector, vector<string> currentStringVector)
{
	vector<string> temp;
	/*
	if(cutTest1(candidateStringVector)){
		return;}
	if(cutTest2(candidateStringVector,currentStringVector)){
		return;}
	*/
	if(currentStringVector.size() == 0){
		if(isPalindrome(tostring(candidateStringVector))){
			palindromeCount++;
			palindromeList.push_back(candidateStringVector);
			return;
		}
	}else if(currentStringVector.size() > 0){
		for(unsigned int i = 0; i < currentStringVector.size(); i++){
			candidateStringVector.push_back(currentStringVector.at(i));
			temp = currentStringVector;
			temp.erase(temp.begin() + i);
			recursiveFindPalindromes(candidateStringVector,temp);	
			candidateStringVector.pop_back();
		}
	}else{
		cout << "ERROR IN RECURSION";
	}
	return;
}

// private function to determine if a string is a palindrome (given, you
// may change this if you want)
bool FindPalindrome::isPalindrome(string currentString) const
{
	locale loc;
	// make sure that the string is lower case...
	convertToLowerCase(currentString);
	// see if the characters are symmetric...
	int stringLength = currentString.size();
	for (int i=0; i<stringLength/2; i++) {
		if (currentString[i] != currentString[stringLength - i - 1]) {
			return false;
		}
	}
	return true;
}

//------------------- PUBLIC CLASS METHODS -------------------------------------

FindPalindrome::FindPalindrome()
{
	palindromeCount = 0;
}

FindPalindrome::~FindPalindrome()
{
	//vectors don't need to be destroyed
	palindromeCount = 0;
	vectorList.clear();
	palindromeList.clear();
	
}

int FindPalindrome::number() const
{
	return palindromeCount;
}

void FindPalindrome::clear()
{
	palindromeCount = 0;
	vectorList.clear();
	palindromeList.clear();
}

bool FindPalindrome::cutTest1(const vector<string> & stringVector)
{
		cout << "\nHit test 1 w/ " ;
	for(auto& l : stringVector){
		cout << l;}
		cout  << "\n";
	
	int ct = 0;
	int highest_ct = 0;
	int highest = 0;
	for(int k = 65; k < 91; k++){
		ct = 0;
		cout << "\nChar set to K = " << k ;
		for(unsigned int i= 0; i < stringVector.size(); i ++){
			for(unsigned int j = 0; j < stringVector[i].length(); j ++){
				if(toupper(stringVector[i][j]) == k){
					ct++;
				}
			}
		}
		
		if(ct > highest){
			highest = ct;
			highest_ct = 1;
		}else if(ct == highest){
			highest_ct++;
		}
		cout << "    count for k = " << ct;
		cout << "    count for highest_ct = " << highest_ct;
	}
	
	if((highest % 2 != 0) && highest_ct > 1){
		return true;
	}
	return false;
}

bool FindPalindrome::cutTest2(const vector<string> & stringVector1,
                              const vector<string> & stringVector2)
{
	unsigned int length = 0;
	
	if(tostring(stringVector1).length() <= tostring(stringVector2).length()){
		length = tostring(stringVector2).length();
	}else{
		length = tostring(stringVector1).length();
	}
	for(unsigned int i = 0; i < length; i ++){
		
	}
	return false;
}

bool FindPalindrome::add(const string & value)
{
	for(unsigned int i= 0; i < value.length(); i ++){
		if((value[i] < 65 && value[i] > 90) || (value[i] < 97 && value[i] > 122)){
			return false;
		}
	}
	if(exist(value)){
		return false;
	}
	vectorList.push_back(value);
	palindromeList.clear();
	vector<string> empty;
	recursiveFindPalindromes(empty, vectorList);
	return true;
}

bool FindPalindrome::add(const vector<string> & stringVector)
{
	string value = "";
	bool test = true;
	unsigned int k;
	for(k = 0; k < stringVector.size(); k++){
		value = stringVector[k];
		for(unsigned int i= 0; i < value.length(); i ++){
			if((value[i] < 65 && value[i] > 90) || (value[i] < 97 && value[i] > 122)){
				test = false;
				break;
			}
		}
		if(exist(value)){
			test = false;
			break;
		}
		vectorList.push_back(value);
	}
	if(!test){
		for(unsigned int j = 0; j < k; j++){
			vectorList.pop_back();
		}
	}
	return test;
}

vector< vector<string> > FindPalindrome::toVector() const
{
	return palindromeList;
}

