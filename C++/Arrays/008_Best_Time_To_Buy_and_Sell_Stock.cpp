/*
https://leetcode.com/problems/best-time-to-buy-and-sell-stock/submissions/
*/

#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


int maxProfit(vector<int>& nums) {
    int min = nums[0], maxprofit = 0;
    for(int i=1; i<nums.size(); i++){
      if(nums[i]<min){
        min = nums[i];
      }
      if((nums[i]-min)>maxprofit){
        maxprofit = (nums[i]-min);
      }
    }
  return maxprofit;
}


int main()
{
  
  //vector<int> myarr1 {7,1,5,3,6,4};
  vector<int> myarr1 {7,6,4,3,1};
  //vector<int> myarr1 {1,1,5};
  
  int ans = maxProfit(myarr1);
    
  cout<< ans <<endl;
    
    return 0;
}

