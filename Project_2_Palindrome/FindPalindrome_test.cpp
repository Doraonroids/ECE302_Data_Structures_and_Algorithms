#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"
#include "FindPalindrome.hpp"

// There should be at least one test per FindPalindrome method

TEST_CASE( "Test FindPalindrome add a non-allowable word", "[FindPalindrome]" )
{
	INFO("Hint: add a single non-allowable word");
	FindPalindrome b;
	REQUIRE(b.add("kayak1") == false);
}

TEST_CASE( "Test FindPalindrome add an allowable word", "[FindPalindrome]" )
{
	FindPalindrome b;
	REQUIRE(b.add("kayak") == true);
}
TEST_CASE( "Test FindPalindrome addvector a non-allowable word", "[FindPalindrome]" )
{
	
	FindPalindrome b;
	std::vector<std::string> testvec = {"kayak", "kayak1"};
	REQUIRE(b.add(testvec) == false);
}
TEST_CASE( "Test FindPalindrome addvector a reused word", "[FindPalindrome]" )
{
	
	FindPalindrome b;
	std::vector<std::string> testvec = {"kayak","A", "TEST", "KO","HAHA","GUY","WO" ,"kayak", "HOPE","THIS","WORKS"};
	REQUIRE(b.add(testvec) == false);
}


TEST_CASE( "Test FindPalindrome test return count function", "[FindPalindrome]" )
{
	FindPalindrome f;
	std::string newString("a");
	f.add(newString);
	newString += "A";
	REQUIRE(f.number() == 1);
	f.add(newString);
	newString += "A";
	REQUIRE(f.number() == 2);
	f.add(newString);
	newString += "A";
	REQUIRE(f.number() == 6);
}

TEST_CASE("Test FindPalindrome test toVector function", "[FindPalindrome]" )
{
	FindPalindrome f;
	std::string newString("a");
	for (int i=0; i<3; i++) {
		f.add(newString);
		newString += "A";
	}
	std::vector<std::vector<std::string> > testvec = 
	{{"a","aA","aAA"},
	{"a","aAA","aA"},
	{"aA","a","aAA"},
	{"aA","aAA","a"},
	{"aAA","a","aA"},
	{"aAA","aA","a"}};
	std::vector<std::vector<std::string> > vectorList = f.toVector();
	for (int i=0; i<vectorList.size(); i++) {
		for (int j=0; j<vectorList[i].size(); j++) {
			REQUIRE(testvec[i][j] == vectorList[i][j]);
		}
		
	}
}
TEST_CASE( "Test FindPalindrome test cutTest1 function", "[FindPalindrome]" )
{
	FindPalindrome f;
	std::vector<std::string> testvec = {"A","A","A","B","B","B"};
	
	REQUIRE(f.cutTest1(testvec) == true);
	testvec.clear();
	testvec = {"A","A","A","B","B","B","A"};
	REQUIRE(f.cutTest1(testvec) == false);
}

TEST_CASE( "Test FindPalindrome test cutTest2 function", "[FindPalindrome]" )
{
	FindPalindrome f;
	std::vector<std::string> testvec1 = {"aa","bb","abc"};
	std::vector<std::string> testvec2 = {"bbaa","ba"};
	
	REQUIRE(f.cutTest2(testvec1,testvec2) == false);
	testvec2.clear();
	testvec2 = {"bbaa","bk"};
	REQUIRE(f.cutTest2(testvec1,testvec2) == true);
}

