/*
https://www.geeksforgeeks.org/chocolate-distribution-problem/
*/

#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int choclateDistribution(vector<int>& nums, int m) {
  if(nums.size()<m || m==0){
    return 0;
  }
  
  sort(nums.begin(), nums.end());
  int min_diff = nums[nums.size()-1]-nums[0];
  for(int i=0; (i+m-1)<nums.size(); i++){
    if((nums[i+m-1]-nums[i])<min_diff){
      min_diff = (nums[i+m-1]-nums[i]);
    }
  }
  return min_diff;
}
int main()
{
    //vector<int> myarr1 {7, 3, 2, 4, 9, 12, 56};
    //int m=3;

    //vector<int> myarr1 {3, 4, 1, 9, 56, 7, 9, 12};
    //int m=5;

    vector<int> myarr1 {12, 4, 7, 9, 2, 23, 25, 41, 
30, 40, 28, 42, 30, 44, 48, 
43, 50};
    int m=7;

    int ans = choclateDistribution(myarr1,m);
    cout << ans<<endl;
    
    return 0;
}
