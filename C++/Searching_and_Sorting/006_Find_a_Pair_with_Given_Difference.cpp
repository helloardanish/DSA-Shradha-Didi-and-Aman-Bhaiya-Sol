// Find a pair with the given difference


/*

https://www.geeksforgeeks.org/find-a-pair-with-the-given-difference/

*/



// C++ program to find a pair with the given difference
#include <bits/stdc++.h>
using namespace std;

// The function assumes that the array is sorted
bool findPair(int arr[], int size, int n)
{
	// Initialize positions of two elements
	int i = 0;
	int j = 1;

	// Search for a pair
	while (i < size && j < size)
	{
		if (i != j && (arr[j] - arr[i] == n || arr[i] - arr[j] == n) )
		{
			cout << "Pair Found: (" << arr[i] <<
						", " << arr[j] << ")";
			return true;
		}
		else if (arr[j]-arr[i] < n)
			j++;
		else
			i++;
	}

	cout << "No such pair";
	return false;
}

// Driver program to test above function
int main()
{
	int arr[] = {1, 8, 30, 40, 100};
	int size = sizeof(arr)/sizeof(arr[0]);
	int n = -60;
	findPair(arr, size, n);
	return 0;
}

// This is code is contributed by rathbhupendra




// using hash table


// C++ program to find a pair with the given difference
#include <bits/stdc++.h>
using namespace std;

// The function assumes that the array is sorted
bool findPair(int arr[], int size, int n)
{
	unordered_map<int, int> mpp;
	for (int i = 0; i < size; i++) {
		mpp[arr[i]]++;

		// Check if any element whose frequency
		// is greater than 1 exist or not for n == 0
		if (n == 0 && mpp[arr[i]] > 1)
			return true;
	}

	// Check if difference is zero and
	// we are unable to find any duplicate or
	// element whose frequency is greater than 1
	// then no such pair found.
	if (n == 0)
		return false;

	for (int i = 0; i < size; i++) {
		if (mpp.find(n + arr[i]) != mpp.end()) {
			cout << "Pair Found: (" << arr[i] << ", "
				<< n + arr[i] << ")";
			return true;
		}
	}

	cout << "No Pair found";
	return false;
}

// Driver program to test above function
int main()
{
	int arr[] = { 1, 8, 30, 40, 100 };
	int size = sizeof(arr) / sizeof(arr[0]);
	int n = -60;
	findPair(arr, size, n);
	return 0;
}
