// Find common elements in three sorted arrays


/*

https://www.geeksforgeeks.org/find-common-elements-three-sorted-arrays/

*/


// C++ program to print common elements in three arrays
#include <bits/stdc++.h>
using namespace std;

// This function prints common elements in ar1
void findCommon(int ar1[], int ar2[], int ar3[], int n1,
				int n2, int n3)
{
	// Initialize starting indexes for ar1[], ar2[] and
	// ar3[]
	int i = 0, j = 0, k = 0;

	// Iterate through three arrays while all arrays have
	// elements
	while (i < n1 && j < n2 && k < n3) {
		// If x = y and y = z, print any of them and move
		// ahead in all arrays
		if (ar1[i] == ar2[j] && ar2[j] == ar3[k]) {
			cout << ar1[i] << " ";
			i++;
			j++;
			k++;
		}

		// x < y
		else if (ar1[i] < ar2[j])
			i++;

		// y < z
		else if (ar2[j] < ar3[k])
			j++;

		// We reach here when x > y and z < y, i.e., z is
		// smallest
		else
			k++;
	}
}

// Driver code
int main()
{
	int ar1[] = { 1, 5, 10, 20, 40, 80 };
	int ar2[] = { 6, 7, 20, 80, 100 };
	int ar3[] = { 3, 4, 15, 20, 30, 70, 80, 120 };
	int n1 = sizeof(ar1) / sizeof(ar1[0]);
	int n2 = sizeof(ar2) / sizeof(ar2[0]);
	int n3 = sizeof(ar3) / sizeof(ar3[0]);

	cout << "Common Elements are ";
	findCommon(ar1, ar2, ar3, n1, n2, n3);
	return 0;
}





// Second method




// C++ program to print common
// elements in three arrays
#include <bits/stdc++.h>
using namespace std;

// This function prints
// common elements in ar1
void findCommon(int ar1[], int ar2[], int ar3[], int n1,
				int n2, int n3)
{

	// Initialize starting indexes
	// for ar1[], ar2[] and
	// ar3[]
	int i = 0, j = 0, k = 0;

	// Declare three variables prev1,
	// prev2, prev3 to track
	// previous element
	int prev1, prev2, prev3;

	// Initialize prev1, prev2,
	// prev3 with INT_MIN
	prev1 = prev2 = prev3 = INT_MIN;

	// Iterate through three arrays
	// while all arrays have
	// elements
	while (i < n1 && j < n2 && k < n3) {

		// If ar1[i] = prev1 and i < n1,
		// keep incrementing i
		while (ar1[i] == prev1 && i < n1)
			i++;

		// If ar2[j] = prev2 and j < n2,
		// keep incrementing j
		while (ar2[j] == prev2 && j < n2)
			j++;

		// If ar3[k] = prev3 and k < n3,
		// keep incrementing k
		while (ar3[k] == prev3 && k < n3)
			k++;

		// If x = y and y = z, print
		// any of them, update
		// prev1 prev2, prev3 and move
		// ahead in each array
		if (ar1[i] == ar2[j] && ar2[j] == ar3[k]) {
			cout << ar1[i] << " ";
			prev1 = ar1[i];
			prev2 = ar2[j];
			prev3 = ar3[k];
			i++;
			j++;
			k++;
		}

		// If x < y, update prev1
		// and increment i
		else if (ar1[i] < ar2[j]) {
			prev1 = ar1[i];
			i++;
		}

		// If y < z, update prev2
		// and increment j
		else if (ar2[j] < ar3[k]) {
			prev2 = ar2[j];
			j++;
		}

		// We reach here when x > y
		// and z < y, i.e., z is
		// smallest update prev3
		// and imcrement k
		else {
			prev3 = ar3[k];
			k++;
		}
	}
}

// Driver code
int main()
{
	int ar1[] = { 1, 5, 10, 20, 40, 80, 80 };
	int ar2[] = { 6, 7, 20, 80, 80, 100 };
	int ar3[] = { 3, 4, 15, 20, 30, 70, 80, 80, 120 };
	int n1 = sizeof(ar1) / sizeof(ar1[0]);
	int n2 = sizeof(ar2) / sizeof(ar2[0]);
	int n3 = sizeof(ar3) / sizeof(ar3[0]);

	cout << "Common Elements are ";
	findCommon(ar1, ar2, ar3, n1, n2, n3);
	return 0;
}
