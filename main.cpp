#include <iostream> 
#include <cmath>


using namespace std; 

/*
Problem: there are three types of edits that can be performed on strings: 
insert a character, remove a character, or replace a character. 
Given two string, write a function to check if they are one edit(or zer edits) away


examples: 
true: pale, ple | pales, pale| pale, bale  
false: pale, bake


assumptions: 
-asscii values only
-case sensitive
-space sentive 


approaches 1: 
Lets notice that when we insert a character we are in theory just removing that same charcter from
the other string. so we can treat these to the same. 

for replace: 
the strings will be the same size. We iterate both strings and compare each corresponding character. There can be at most 
one difference bettween the two 

for insert or remove
iterate through both strings comparaing each other. use two separate indexs. if we find one difference then keep smaller index the same and increment 
the larger index. and continue interating. there there are any more difference then the two string are more than one edit away. 

O(N)
O(1) space

*/

bool checkOneAway(const string & a, const string & b)
{
	int numberOfDifference = 1; 


	if(a.size() == b.size())
	{
		for(int i = 0; i < a.size(); i++)
		{
			if(a.at(i)!=b.at(i))
			{
				numberOfDifference--; 
				if(numberOfDifference<0)
					return false; 
			}
		}
	}
	else
	{
		int i = 0, j = 0; 
		while(i < a.size() & j< b.size())
		{
			if(a.at(i)!=b.at(j))
			{
				numberOfDifference--; 
				if(numberOfDifference<0)
					return false; 

				if(a.size() < b.size())
					j++;
				else
					i++;
			}
			else
			{
				i++; 
				j++; 
			}
		}
	}

	return true; 
}



int main()
{

	cout << "True: " <<checkOneAway("abc", "ab") << endl; 
	cout << "True: " <<checkOneAway("abc", "abd")<<  endl; 
	cout << "True: " <<checkOneAway("abc", "abe") <<  endl; 
	cout << "false: " <<checkOneAway("abc", "abde") <<  endl; 
	cout << "false: " <<checkOneAway("abc", "abee") <<  endl;
	cout << "false: " <<checkOneAway("abc", "abff") <<  endl;

	return 0; 
}