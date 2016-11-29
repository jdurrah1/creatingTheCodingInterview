#include <iostream> 
#include <vector> 


using namespace std; 

/*
problem: given an image represented by an NxN matrix, where each pixel in the image is 4 bytes,
write a method to rotate the image by 90 degrees. Can you do this in place? 

input: 
output: rotated matrix

assuptions: 
-can store in memory

example 1: 
1 2 ----> 2(1,2)
3 4--->(2,2)

3 1
4 2--->(2,2)
|
|
|
v
(2,1)
example 2: 
1 2 3 -->(1,3)
4 5 6
7 8 9

7 4 1
8 5 2
9 6 3--(3,3)


approach 1: 
let original matrix be matrix A. Create a new matrix B of the same size as A. 
Transpose(reverse) each collumn in A into a row vector. Place the row vector in the 
corresponding row in matrix B. i.e. transpose column 1 and put the values into
row 1. 

e.x.: 
1 2 3
4 5 6
7 8 9

column 1: 
1
4
7
column 1 transposed: 
7 4 1

add row to row 1 of matrix B: 

7 4 1
8 5 2
9 6 3

O(n^2) time 
O(n^2) memory

approach 2: 



*/



vector<vector<int> > rotateMatrix(vector<vector<int> > A)
{

	vector<vector<int> > B; 

	for(int j= 0; j < A.at(0).size(); j++)
	{
		vector<int> temp; 
		for(int i = A.size()-1; i >=0; i--)
		{
			temp.push_back(A.at(i).at(j));

		}
		B.push_back(temp);
	}
	

	return B; 
}



int main()
{

	vector<vector<int> > A; 

	int counter = 0; 
		for(int i = 0; i < 5; i++)
		{
			vector<int> temp; 
			for(int j = 0; j < 5; j++)
			{
				temp.push_back(counter);
				counter++;
			}
			A.push_back(temp);
		}

	vector<vector<int> > B = rotateMatrix(A); 

		for(int i = 0; i < 5; i++)
		{
			vector<int> temp; 
			for(int j = 0; j < 5; j++)
			{
				cout << B.at(i).at(j) << " "; 
			}
			cout << endl;
		}

	return 0; 
}