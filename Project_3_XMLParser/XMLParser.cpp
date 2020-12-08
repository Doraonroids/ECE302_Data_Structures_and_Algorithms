// Project 3 -- XML Parsing Project

/** XML parsing class implementation.
    @file XMLParser.cpp */

#include <string>
#include <assert.h>
#include "XMLParser.hpp"

// TODO: Implement the constructor here
XMLParser::XMLParser()
{
	parseStack = new Stack<std::string>;
	elementNameBag = new Bag<std::string>;
	flag = true;
}  // end default constructor

// TODO: Implement the destructor here
XMLParser::~XMLParser()

{
	delete parseStack;
	delete elementNameBag;
}  // end destructor

// TODO: Implement a helper function to delete attributes from a START_TAG
// or EMPTY_TAG string (you can change this...)
static std::string deleteAttributes(std::string input)
{	
	bool found_flag = 0;
	for(unsigned int i = 0; i < input.length()-1; i++){
		if(input.at(i) == ' '){
			found_flag = 1;
			input.erase(i);
		}else if(found_flag){
			input.erase(i);
		}
	}
	return input;
}
// TODO: Implement the tokenizeInputString method
bool XMLParser::tokenizeInputString(const std::string &inputString)
{
	bool blank_flag= false;
	TokenStruct temp;
	TokenStruct *p = &temp;
	unsigned int i = 0, length = 0;
	char h,l;
	while(i < inputString.length()-3){
		p->tokenString = "";
		if(inputString[i] == '<'){
			do{
				p->tokenString += inputString[i];
			
				i++;
				if(inputString[i] == '<'){
					tokenizedInputVector.clear();
					flag = false;
					return false;
				}
			}while(inputString[i] != '>');
			p->tokenString += inputString[i];
			i++;
			tokenizedInputVector.push_back(temp);
		}else{
			
			do{
				p->tokenString += inputString[i];
			
				i++;
				if(inputString[i] == '>'){
					tokenizedInputVector.clear();
					flag = false;
					return false;
				}
			}while(inputString[i] != '<');
			tokenizedInputVector.push_back(temp);
		}
	}
	
	for(unsigned int j = 0; j < tokenizedInputVector.size(); j ++){
		temp = tokenizedInputVector[j];
		if(p->tokenString.at(0) != '<'){
			for(unsigned int k = 0; k < p->tokenString.length(); k ++){
				h = p->tokenString.at(k);
				if( h > 32 && h < 127){
					blank_flag = false;
					break;
				}else{
					blank_flag = true;
				}
			}
			if(blank_flag == true){
				tokenizedInputVector.erase(tokenizedInputVector.begin() + j);
			}else{
				tokenizedInputVector[j].tokenType = CONTENT;
			}
		}
	}
	for(unsigned int ha = 0; ha < tokenizedInputVector.size(); ha ++){
		if(tokenizedInputVector[ha].tokenString.at(0) == '<'){
			h = tokenizedInputVector[ha].tokenString.at(1);
			length = tokenizedInputVector[ha].tokenString.length();
			l = tokenizedInputVector[ha].tokenString.at(length - 2);
			if(h == '?' && l == '?'){
				tokenizedInputVector[ha].tokenType = DECLARATION;
				tokenizedInputVector[ha].tokenString = tokenizedInputVector[ha].tokenString.substr(2,length - 4);
			}else if(h == '/'){
				tokenizedInputVector[ha].tokenString = deleteAttributes(tokenizedInputVector[ha].tokenString);
				tokenizedInputVector[ha].tokenType = END_TAG;
				tokenizedInputVector[ha].tokenString = tokenizedInputVector[ha].tokenString.substr(2,length - 3);
			}else if(l == '/'){
				tokenizedInputVector[ha].tokenType = EMPTY_TAG;
				tokenizedInputVector[ha].tokenString = tokenizedInputVector[ha].tokenString.substr(1,length - 3);
			}else{
				tokenizedInputVector[ha].tokenString = deleteAttributes(tokenizedInputVector[ha].tokenString);
				tokenizedInputVector[ha].tokenType = START_TAG;
				tokenizedInputVector[ha].tokenString = tokenizedInputVector[ha].tokenString.substr(1,length - 2);
			}
			elementNameBag->add(tokenizedInputVector[ha].tokenString);
		}
	}

	return true;
}  // end



// TODO: Implement the parseTokenizedInput method here
bool XMLParser::parseTokenizedInput()
{
	char test;
	for(unsigned int i = 0; i < tokenizedInputVector.size();i++)
	{		
		if(tokenizedInputVector[i].tokenType != CONTENT && tokenizedInputVector[i].tokenType != DECLARATION)
		{


			for(unsigned int j = 0; j < tokenizedInputVector[i].tokenString.length(); j++)
			{
				test = tokenizedInputVector[i].tokenString.at(j);
			
				if(j == 0 && (test == 45 || test == 43 || (test > 47 && test < 58)))
				{
					flag = false;
					return false;
				}
				else if(test < 42 || test == 44 || (test > 45 && test <48) || (test > 58 && test < 65) || (test > 90 && test <95)||(test >95 && test < 97) || test > 122)
				{
					flag = false;
					return false;
				}
			}
		}
	}

	for(unsigned int l = 0;l < tokenizedInputVector.size();l++)
	{
		
		std::string tmpstr = tokenizedInputVector[l].tokenString;
		if(tokenizedInputVector[l].tokenType == START_TAG)
		{
			
			parseStack->push(tmpstr);
		}
		else if(tokenizedInputVector[l].tokenType == END_TAG)
		{
			
			if(parseStack->peek() == tokenizedInputVector[l].tokenString)
			{
				
				parseStack->pop();
			}
			else
			{
				flag = false;
				return false;
			}
		}

	}
	return true;
}

// TODO: Implement the clear method here
void XMLParser::clear()
{
	tokenizedInputVector.clear();
	parseStack->clear();
	elementNameBag->clear();
}

vector<TokenStruct> XMLParser::returnTokenizedInput() const
{
	return tokenizedInputVector;
}

// TODO: Implement the containsElementName method
bool XMLParser::containsElementName(const std::string &inputString) const
{	
	if(flag){
		return elementNameBag->contains(inputString);
	}else{
		return false;
	}
}

// TODO: Implement the frequencyElementName method
int XMLParser::frequencyElementName(const std::string &inputString) const
{
	if(flag){
		return (elementNameBag->getFrequencyOf(inputString))/2;
	}else{
		return 0;
	}
	
}

