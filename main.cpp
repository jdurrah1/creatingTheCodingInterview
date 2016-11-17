#include <iostream> 


using namespace std; 




/*
Problem: Write a method to replace all spaces in a string with '%20'. You may assume that the string has sufficient space at the end to hold the additional 
characters, and that youa are given the 'true' length of the string.

Example: 
input: "Mr John Smith     ", 13
output: "Mr%20John%20Smith"

input: string, int true length
output: string with whitespaces replaced with %20

assuptions:
-there is enough space at the end
-we can't use any additional storage i.e. solution must be o(1)


approach 1: 
scan through the string and get the number of spaces. Since we know the number of spaces we know the new true length of the document
so we know where the last character should be placed. So we essentailly rebuild the string starting from the right character

time complexity: N + N
space complexity: O(1)

R: we have true length of string
M: input string
E: return input string with spaces replaced with %20
*/

string urlify(string str, int trueLength)
{

	int numberOfSpaces = 0; 

	for(int i = 0; i < trueLength; i++)
	{
		if(str.at(i)==' ')
			numberOfSpaces++;
	}

	int index = numberOfSpaces*2 + trueLength; 
	str.at(index) = '\0';
	for(int i = trueLength-1; i >=0; i--)
	{
		cout << str << endl ;
		if(str.at(i)==' ')
		{
			str.at(index-1) ='0';
			str.at(index-2) ='2';
			str.at(index-3) ='%';
			index -= 3; 
		}
		else
		{
			str.at(index-1) = str.at(i); 
			index--; 
		}
	}


	return str; 
}

int main()
{

	cout << "Mr John Smith        13: " << urlify("Mr John Smith                 ", 13) <<endl; 

	return 0; 
}