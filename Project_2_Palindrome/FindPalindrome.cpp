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

bool FindPalindrome::exist(std::string s) const{
	int start = 0, end = vectorList.size() - 1;
	while (start <= end) {
		int middle = start + (end - start) / 2;
		
		if (convertToLowerCase(s) == convertToLowerCase(vectorList[middle]))
			return true;
		if (s > (vectorList[middle])){
			start = middle + 1;
		}else{
			end = middle - 1;
		}
	}
	return false;
}


// private recursive function. Must use this signature!
void FindPalindrome::recursiveFindPalindromes(vector<string>
        candidateStringVector, vector<string> currentStringVector)
{
	// TODO need to implement this recursive function!
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
	char most = 'A';
	int ct = 0;
	int highest_ct = 0;
	int highest = 0;
	for(int k = 65; k < 91; k++){
		ct = 0;
		most = k;
		for(unsigned int i= 0; i < stringVector.size(); i ++){
			for(unsigned int j = 0; j < stringVector[i].length(); j ++){
				if(toupper(stringVector[i][j]) == most){
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
	if((highest_ct % 2 != 0) && highest_ct > 1){
		return false;
	}
	return true;
}

bool FindPalindrome::cutTest2(const vector<string> & stringVector1,
                              const vector<string> & stringVector2)
{
	
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
	// TODO need to implement this...
	vector<vector<string>> returnThingie;
	return returnThingie;
}

