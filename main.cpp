#include <iostream> 


using namespace std; 

/*
Implement a method to perform basic string compression using the counts of repeated characters.
For example, the string aabcccccaaa would become a2b1c5a3. 
If the "compressed" string would not become smaller than the original string, 
your method should return the original string. 
You can assume the string has only uppercase and lowercase letters (a - z).

input: string
output: compressed string or orginal string if compressed string not actually smaller

assumptions: 
-asscii
-case sensitive 
-space sentive


examples:
aabbccddeee -> a2b2c2d2e3

approach 1: 
Add the first character to the new output string. Count how many times the first character appears consecutively. 
When we reach a new string add the count to the output string, reinitialize our count and add the new character 
to the output string. repeat until we reach the end of the string

time complextiy: 
O(N) 
space complexity: 
O(N)

*/

string compressString(const string  & str)
{
	string compressedString = ""; 
 	int count = 0; 
 	char currentChar ; 
	for(int i = 0; i < str.size(); i++)
	{
		if(currentChar!= str.at(i))
		{
			if(count != 0)
				compressedString += (std::to_string(count));

			compressedString.push_back(str.at(i));
			currentChar = str.at(i); 
			count=1; 
		}
		else
		{
			count++; 
		}
	}
	compressedString += (std::to_string(count));
	
	if(compressedString.size() >= str.size())
		return str; 

	return compressedString; 
}

int main()
{
	cout << "aabbccddeee: "<< compressString("aabbccddeee") << endl; 

	return 0; 
}