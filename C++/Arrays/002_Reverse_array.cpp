/*
https://www.geeksforgeeks.org/write-a-program-to-reverse-an-array-or-string/
*/

#include <bits/stdc++.h>

using namespace std;

vector<int> reverseArray(vector<int> arr){
  int start=0;
  int end=arr.size()-1;
  while(start < end){
    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;
    ++start;
    --end;
  }
  return arr;
}

int main()
{
    vector<int> myarr1 {2,3,5,4,100,6,2,3,3};
    //vector<int> myarr1 {2,3,4,1,4,5};
    

    vector<int> ans = reverseArray(myarr1);
    
    for(auto x:ans){
      cout << x << " ";
    }
    cout << endl;
  
    return 0;
}
