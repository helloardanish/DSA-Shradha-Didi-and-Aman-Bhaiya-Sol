/*
https://leetcode.com/problems/maximum-subarray/
*/

#include <bits/stdc++.h>

using namespace std;

int maxSubArray(vector<int>& nums) {
  int maxHere = 0;
  int maxSoFar = nums[0];
  
  if(nums.size() == 1){
      return maxSoFar;
  }
  
  for(int i = 0;i<nums.size();i++)
  {
      maxHere += nums[i];
      maxSoFar = max(maxSoFar, maxHere);
      maxHere = max(maxHere, 0);
  }
  return maxSoFar;
}
int main()
{
    vector<int> myarr1 {-2,1,-3,4,-1,2,1,-5,4};
    //vector<int> myarr1 {2,3,4,1,4,5};
    

    int ans = maxSubArray(myarr1);
    cout << ans<<endl;
  
    return 0;
}
