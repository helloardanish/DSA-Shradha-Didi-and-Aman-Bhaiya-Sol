// Ceiling in a sorted array



/*

https://www.geeksforgeeks.org/ceiling-in-a-sorted-array/

*/


#include <bits/stdc++.h>
using namespace std;

/* Function to get index of
	ceiling of x in arr[low..high]*/
int ceilSearch(int arr[], int low, int high, int x)
{

// base condition if length of arr == 0 then return -1
if (x == 0)
{
	return -1;
}
int mid;

/* this while loop function will run until
condition not break once condition break
	loop will return start and ans is low
	which will be next smallest greater than target
	which is ceiling*/
while (low <= high)
{
	mid = low + (high - low) / 2;
	if (arr[mid] == x)
	{
	return mid;
	}
	else if (x < arr[mid])
	{

	high = mid - 1;
	}
	else
	{

	low = mid + 1;
	}

}
return low;
}

/* step 1 : { low = 1, 2, 8, 10= mid, 10, 12, 19= high};
				if( x < mid) yes set high = mid -1;
	step 2 : { low = 1, 2 = mid, 8 = high, 10, 10, 12, 19};
				if( x < mid) no set low = mid + 1;
	step 3 : {1, 2, 8 = high,low,low, 10, 10, 12, 19};
				if( x == mid ) yes return mid
				if(x < mid ) no low = mid + 1
	step 4 : {1, 2, 8 = high,mid, 10 = low, 10, 12, 19};
				check while(low < = high)
				condition break and return low which will next greater of target */

/* Driver program to check above functions */
int main()
{
int arr[] = {1, 2, 8, 10, 10, 12, 19};
int n = sizeof(arr) / sizeof(arr[0]);
int x = 8;
int index = ceilSearch(arr, 0, n - 1, x);
if (index == -1)
{
	cout << "Ceiling of " << x << " does not exist in an array";
}
else
{
	cout << "Ceiling of " << x << " is " << arr[index];
}
return 0;
}

// This code is contributed by Machhaliya Muhammad
