/*
https://leetcode.com/problems/maximum-product-subarray/
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxProduct(vector<int>& nums) {
  int best = nums[0];
  for(int num:nums){
    if(num>best){
      best=num;
    }
  }
  int temp;
  int currMax =1;
  int currMin = 1;
  
  for(int val:nums){
    if(val==0){
      currMax=1;
      currMin=1;
      continue;
    }

    temp = currMax*val;
    currMax = max(val*currMax, max(val*currMin, val));
    currMin = min(temp, min(val*currMin, val));
    best = max(temp, best);
  }
  return best;
}
int main()
{
  
  //vector<int> myarr1 {7,1,5,3,6,4};
  //vector<int> myarr1 {3, 1, 2, 5, 3};
  //vector<int> myarr1 {0,1,0,2,1,0,1,3,2,1,2,1};
  vector<int> myarr1 {-2,0,-1};

  
  int ans = maxProduct(myarr1); 
  cout << ans << endl;
  return 0;
}

// check solution explanation : https://youtu.be/lXVy6YWFcRM
