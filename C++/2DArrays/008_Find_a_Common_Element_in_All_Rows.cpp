// Find a common element in all rows of a given row-wise sorted matrix



/*

https://www.geeksforgeeks.org/find-common-element-rows-row-wise-sorted-matrix/

*/



// A C++ program to find a common element in all rows of a
// row wise sorted array
#include <bits/stdc++.h>
using namespace std;

// Specify number of rows and columns
#define M 4
#define N 5

// Returns common element in all rows of mat[M][N]. If there is no
// common element, then -1 is returned
int findCommon(int mat[M][N])
{
	// An array to store indexes of current last column
	int column[M];
	int min_row; // To store index of row whose current
	// last element is minimum

	// Initialize current last element of all rows
	int i;
	for (i = 0; i < M; i++)
		column[i] = N - 1;

	min_row = 0; // Initialize min_row as first row

	// Keep finding min_row in current last column, till either
	// all elements of last column become same or we hit first column.
	while (column[min_row] >= 0) {
		// Find minimum in current last column
		for (i = 0; i < M; i++) {
			if (mat[i][column[i]] < mat[min_row][column[min_row]])
				min_row = i;
		}

		// eq_count is count of elements equal to minimum in current last
		// column.
		int eq_count = 0;

		// Traverse current last column elements again to update it
		for (i = 0; i < M; i++) {
			// Decrease last column index of a row whose value is more
			// than minimum.
			if (mat[i][column[i]] > mat[min_row][column[min_row]]) {
				if (column[i] == 0)
					return -1;

				column[i] -= 1; // Reduce last column index by 1
			}
			else
				eq_count++;
		}

		// If equal count becomes M, return the value
		if (eq_count == M)
			return mat[min_row][column[min_row]];
	}
	return -1;
}

// Driver Code
int main()
{
	int mat[M][N] = {
		{ 1, 2, 3, 4, 5 },
		{ 2, 4, 5, 8, 10 },
		{ 3, 5, 7, 9, 11 },
		{ 1, 3, 5, 7, 9 },
	};
	int result = findCommon(mat);
	if (result == -1)
		cout << "No common element";
	else
		cout << "Common element is " << result;
	return 0;
}

// This code is contributed
// by Akanksha Rai


// Check another code using hashmap on the geekforgeeks too for explanation


// C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;

// Specify number of rows and columns
#define M 4
#define N 5

// Returns common element in all rows of mat[M][N]. If there is no
// common element, then -1 is returned
int findCommon(int mat[M][N])
{
	// A hash map to store count of elements
	unordered_map<int, int> cnt;

	int i, j;

	for (i = 0; i < M; i++) {

		// Increment the count of first
		// element of the row
		cnt[mat[i][0]]++;

		// Starting from the second element
		// of the current row
		for (j = 1; j < N; j++) {

			// If current element is different from
			// the previous element i.e. it is appearing
			// for the first time in the current row
			if (mat[i][j] != mat[i][j - 1])
				cnt[mat[i][j]]++;
		}
	}

	// Find element having count equal to number of rows
	for (auto ele : cnt) {
		if (ele.second == M)
			return ele.first;
	}

	// No such element found
	return -1;
}

// Driver Code
int main()
{
	int mat[M][N] = {
		{ 1, 2, 3, 4, 5 },
		{ 2, 4, 5, 8, 10 },
		{ 3, 5, 7, 9, 11 },
		{ 1, 3, 5, 7, 9 },
	};
	int result = findCommon(mat);
	if (result == -1)
		cout << "No common element";
	else
		cout << "Common element is " << result;

	return 0;
}
