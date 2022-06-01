// Permute two arrays such that sum of every pair is greater or equal to K


/*

https://www.geeksforgeeks.org/permute-two-arrays-sum-every-pair-greater-equal-k/

*/


// Idea : Sort first array in increasing order and second one in decreasing order or vice-versa.


// C++ program to check whether permutation of two
// arrays satisfy the condition a[i] + b[i] >= k.
#include<bits/stdc++.h>
using namespace std;

// Check whether any permutation exists which
// satisfy the condition.
bool isPossible(int a[], int b[], int n, int k)
{
	// Sort the array a[] in decreasing order.
	sort(a, a + n);

	// Sort the array b[] in increasing order.
	sort(b, b + n, greater<int>());

	// Checking condition on each index.
	for (int i = 0; i < n; i++)
		if (a[i] + b[i] < k)
			return false;

	return true;
}

// Driven Program
int main()
{
	int a[] = { 2, 1, 3 };
	int b[] = { 7, 8, 9 };
	int k = 10;
	int n = sizeof(a)/sizeof(a[0]);

	isPossible(a, b, n, k) ? cout << "Yes" :
							cout << "No";
	return 0;
}
