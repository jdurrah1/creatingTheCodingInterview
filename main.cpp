#include <iostream> 
#include <vector> 


using namespace std; 

/*

input: string
output: bool - true if unique, false if not



Assupmptions 
- ascci 126 values only
- counting spaces? 
- What could this be used for?
- How could the input grow? 
- case count? 


Examples: 
	True: abcde, "", " ", a d
	False: aa, bb, " , "


Approach 1: 
Start from the left most char, scan all following char's. 
If the same char is found then return false. if we reach the end of the string 
then all characters are unique

time complexity: N +  (N-1) + (N-2) + (N-3) + .... + 1 = (N-1)N/2 = O(N*N)
Space complexity: O(1)

Approach 2: 
Create a vector of size 126 where each position is associated with 
the corresponding assci value ie index 0 = a. Use the char to index the vector incrementing each
char found. If we ever find that a count is more than one then we have a duplicate char found

time complexity: O(N)
Space complexity: O(1) - because the size of the vector is constant and does not depend on the size n of the input string

Approach 3: No addional data structures
- sort the string O(nlogn). could take up additional space depending on 
sorting algorithm I choose


obvious: return false if the length is more than 128

R: input is a string, characters are ASCII 
M: nothing
E: returns true if all characters unique, false otherwise
*/



bool isUnique(string str)
{

	if(str.size() > 128)
		return false; 

	vector<bool> charUsed(128, 0);

	for(int i = 0; i < str.size(); i++)
	{
		int index  = (int) str.at(i); 
		if(!charUsed.at(index))
			charUsed.at(index) = true; 
		else
			return false; 
	}

	return true; 
}


int main()
{

	//test
	cout << "False: " << isUnique("hhello") << endl ;
	cout << "true: " << isUnique("") << endl ;
	cout << "False: " << isUnique("  ") << endl ;
	cout << "True: " << isUnique("h l") << endl ;
	cout << "True: " << isUnique(" ") << endl ;
	cout << "True: " << isUnique("le") << endl ;


	return 0; 
}