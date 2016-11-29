#include <iostream> 


using namespace std; 


/*

problem: write an algorithm such that if an element in an MxN matrix is 0, its entire
row and column are set to 0

input: matrix
output: modified matrix based on the conditions in the given problem statement

assumption: 
-matrix will never be empty
-matrix could be a zero matrix


example: 

1 2 3
4 5 6
7 8 0

1 2 0
4 5 0
0 0 0


approach 1: 
Create an aditional matrix B that is a copy of matrix A. Scan the input matrix A. If a zero
is found in matrix A at position i, j, change all values row i and column j of matrix B to 
zero

time complexity: O(n^2)
space complexity: O(n^2)


reduce space used

appoach 2: 
Instead of creating an additional matrix B, we create two vectors of boolean values. 
the vectors will be the same size as the number of rows or columns in matrix A. Each index 
in the vector will correspond the the row or column of the matrix. 

Scan through the matrix A and for every zero found mark the correspond row vector and column vector
to true indicating that the row and column should be zerod out

scan though row vector
if value is true then zero out all values in corresponding row in matrix
do the same for the colmn vector

time complexity: O(n^2)
space compledity: O(max(m,n))


*/

void zeroMatrix(vector< vector< int> > & A)
{
	//check A not empty

	vector<bool> rowZeros(A.size(), false); 
	vector<bool> colZeros(A.at(0).size(), false); 

	for(int i = 0; i < A.size(); i++)
	{

		for(int j = 0; j < A.at(0).size(); j++)
		{
			if(A.at(i).at(j)==0)
			{
				rowZeros.at(i) = true; 
				colZeros.at(j) = true; 
			}
		}
	}

	for(int i = 0; i < rowZeros.size(); i++)
	{
		if(rowZeros.at(i))
			for(int  j = 0; j < A.at(0).size(); j++)
			{
				A.at(i).at(j) = 0; 
			}
	}

	for(int j = 0; j < colZeros.size(); j++)
	{
		if(colZeros.at(j))
			for(int  i = 0; i < A.size(); i++)
			{
				A.at(i).at(j) = 0; 
			}
	}

	return; 
}





int main()
{

	cout << "Hello World" << endl; 

	return 0; 
}
















