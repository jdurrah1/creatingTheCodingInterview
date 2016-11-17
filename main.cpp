#include <iostream> 
#include <vector>


using namespace std; 

/*
Problme: Given a string, write a function to check if it is a permutation of a palindrome. A palindrome is a word or phrase that is the same forwards and backwards. 
A permutation is a rearrangement of letters. The palindrome does not need to be limited to just dictionary words


input: string
output: permutation of that string

asspution 
-ascii
-case sentive
-space sensitive 


examples:

approach: 
- when thinking about a palindrome we realize that we must be able to represent the left side on the right side. so there must be an 
equal number of characters on the left and right side. Since there are only two side there must be an even number of characters with the exception of a 
string of odd length in which case there must be one and only one character with an odd number of occurences. 

We could create a charCount vector and scan through the string increment the corresponding index based on its asssci value. After our initiall scan 
we iterate thought the charCount vector and check to see if all counts are even or in the case of a odd length vector( there is only one ) odd length
count
*/

bool isPalindromePermutation(const string & str)
{
	vector<int> charCount(128, 0);
	int numberOfOddCounts = 0; 

	for(int i = 0; i < str.size(); i++)
	{
		int index = (int) str.at(i); 
		charCount.at(index)++; 
	}

	if(str.size()%2!=0)
	{
		numberOfOddCounts = 1; 
	}

	for(int i = 0; i < charCount.size(); i++)
	{
		if(charCount.at(i)%2 != 0)
		{
			numberOfOddCounts--; 
			if(numberOfOddCounts< 0)
				return false; 
		}
	}


	return true; 
}




int main()
{

	cout << "true: " <<isPalindromePermutation("ono") << endl; 
	cout << "true: " <<isPalindromePermutation("tactcoa") << endl; 
	cout << "true: " <<isPalindromePermutation("heh") << endl; 
	cout << "false: " <<isPalindromePermutation("oono") << endl; 
	cout << "false: " <<isPalindromePermutation("odno") << endl; 
	cout << "false: " <<isPalindromePermutation("ondddo") << endl; 

	return 0; 
}