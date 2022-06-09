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





// Using vector



#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool ifPairExists(vector<int> arr1, vector<int> arr2, int k){
  if(arr1.size()!=arr2.size()) return false;
  if(arr1.size()==0 || arr2.size()==0) return true;
  
  sort(arr1.begin(), arr1.end());

  sort(arr2.begin(), arr2.end(), greater<int>());

  for(int i=0; i<arr1.size(); i++){
    int sum = arr1[i] + arr2[i];
    if(sum<k){
      return false;
    }
  }
  return true;
} 

int main() {

  vector<int> arr1 = {2,1,3};
  vector<int> arr2 = {7,8,9};

  //vector<int> arr1 = {1,2,2,1};
  //vector<int> arr2 = {3,3,3,4};
  int k=10;
  bool ans = ifPairExists(arr1, arr2, k);
  if(ans){
    cout << "YES" <<endl;
  }else{
    cout << "NO" <<endl;
  }
  cout << "\n";
}
