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
			
			if(cutTest1(candidateStringVector)){
				//cout << "\t**cutTest1 passed true** with :" << tostring(candidateStringVector) << "\n";
				return;
			}
			if(cutTest2(candidateStringVector,temp)){
				//cout << "\t**cutTest2 passed true** with :" << tostring(candidateStringVector) << "\n";
				return;
			}
			
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
	int ct = 0;
	int highest_ct = 0;
	int highest = 0;
	for(int k = 65; k < 91; k++){
		ct = 0;
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
	}
	
	if((highest % 2 != 0) && highest_ct > 1 && highest > 1){
		return true;
	}
	return false;
}

bool FindPalindrome::cutTest2(const vector<string> & stringVector1,
                              const vector<string> & stringVector2)
{
	unsigned int lengthsmall= 0, lengthlong = 0;
	bool string1smaller = false;
	int test = 0;
	string string1 = "", string2= "";
	//make vectors strings for easy use
	string1 = tostring(stringVector1);
	string2 = tostring(stringVector2);
	//make lowercase for easy comparison
	convertToLowerCase(string1);
	convertToLowerCase(string2);
	//used to count characters in vectors
	vector<int> count1,count2;
	//fill vectors with 0's
	for(unsigned int k = 0; k < 26; k ++){
		count1.push_back(0);
		count2.push_back(0);
	}
	//decide the smaller string and set length
	if(string1.length() >= string2.length()){
		lengthsmall = string2.length();
		lengthlong = string1.length();
	}else{
		lengthsmall = string1.length();
		lengthlong= string2.length();
		string1smaller = true;
	}
	//count characters in strings in proper place
	for(unsigned int i = 0; i < lengthsmall; i ++){
		if(string1smaller){
			count1[string1[i]-97]++;
		}else{
			count1[string2[i]-97]++;
		}
	}for(unsigned int j = 0; j < lengthlong; j ++){
		if(string1smaller){
			count2[string2[j]-97]++;
		}else{
			count2[string1[j]-97]++;
		}
	}
	//determine test
	for(unsigned int m = 0; m < 26; m ++){
		if(count2[m] < count1[m]){
			test++;
		}
	}
	if(test > 0)
		test = 1;
	
	return test;
}

bool FindPalindrome::add(const string & value)
{
	//parse through string
	for(unsigned int i= 0; i < value.length(); i ++){
		//test for character check
		if((value[i] > 90 && value[i] < 97) || value[i] > 122 || value[i] < 65){
			return false;
		}
	}
	//see if string exists already
	if(exist(value)){
		return false;
	}
	//add back of vector list
	vectorList.push_back(value);
	palindromeList.clear();
	
	palindromeCount = 0;
	vector<string> empty;
	recursiveFindPalindromes(empty, vectorList);
	return true;
}

bool FindPalindrome::add(const vector<string> & stringVector)
{
	string value = "";
	bool test = true;
	unsigned int k;
	//parse through array
	for(k = 0; k < stringVector.size(); k++){
		//get the string at point k
		value = stringVector[k];
		//parse throught string
		for(unsigned int i= 0; i < value.length(); i ++){
			//character test
			if((value[i] > 90 && value[i] < 97) || value[i] > 122 || value[i] < 65){
				return false;
			}
		}
		//see if string exists already
		if(exist(value)){
			return false;
		}else{
			vectorList.push_back(value);
		}
		
	}
	palindromeList.clear();
	vector<string> empty;
	palindromeCount = 0;
	recursiveFindPalindromes(empty, vectorList);
	return true;
}

vector< vector<string> > FindPalindrome::toVector() const
{
	return palindromeList;
}


