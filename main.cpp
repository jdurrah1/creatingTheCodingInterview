#include <iostream> 
#include <vector>


using namespace std; 



/*
Problem: Given two string, write a method to decide if one is a prmutation of the other

input: string a, string b
output: true - if a permutatinon of b, false otherwise


assumption: 
-assci values
-uppercase and lowercase are different 
-permutation is when the same letters are present in both strings


example:
true: (aa,aa), (ac, ca), ("", "")

fasle: ("  ", "   "), ("aaa", "aa"), ("abc", "abcd")


approach 1: 
check same size(differ in size then not permutations). 
interate through string a and scan string b for a corresponding char. Track which 
chars have been matched. When you can't find a unused corresponding char then 
string a is not a permutation of string b

time complexity: N(N) - O(N*N)
space complexity: O(N)

approach 2:
the char counts must equal in both strings so we could create a vector where the index of the vector corresponds with 
the char's ascci value. Scan string a and increment counts in our charCount vector. Scan string b and decrement counts in 
char Count vector. if we find that after decrement a charCount the value is negative then string a is not a permutation of string b

time complexity 2N = O(N)
space compledity: O(c) = O(1)


R: a and B are strings
M: nothing
E: returns rather or not a is a permutation of be and vice versa
*/

bool checkPermutation(const string & a, const string & b)
{
	if(a.size() != b.size())
		return false; 

	vector<int> charCounts(128, 0);

	for(int i = 0; i < a.size(); i++)
	{
		int index = (int) a.at(i); 
		charCounts.at(index)++; 
	}

	for(int i = 0; i < b.size(); i++)
	{
		int index = (int) b.at(i); 
		charCounts.at(index)--; 
		if(charCounts.at(index) <0)
			return false; 
	}

	return true; 
}


int main()
{

	cout << "true: " << checkPermutation(" ", " ") << endl; 
	cout << "true: " << checkPermutation("ab ", "ba ") << endl;
	cout << "true: " << checkPermutation("aa", "aa") << endl;
	cout << "false: " << checkPermutation("ab", "aa") << endl;
	cout << "false: " << checkPermutation("cd", "ed") << endl;
	cout << "false: " << checkPermutation("aa", "aaa") << endl;


	return 0; 
}