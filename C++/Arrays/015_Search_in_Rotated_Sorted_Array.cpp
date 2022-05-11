/*
https://leetcode.com/problems/search-in-rotated-sorted-array/
*/

#include <iostream>
#include <vector>

using namespace std;

int search(vector<int>& nums, int target) {
    int l=0,r=nums.size()-1;
    int mid;
    while(l<=r){
        mid = ((l+r)/2);
        if(target == nums[mid]){
            return mid;
        }
        
        //left side
        if(nums[l]<=nums[mid]){
            if(target< nums[l]){
                l=mid+1;
            }else if(target > nums[mid]){
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        //right side
        else{
            if (target>nums[r]){
                r = mid-1;
            }else if(target < nums[mid]){
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
    }
    return -1;   
}
int main()
{
  
  vector<int> myarr1 {4,5,6,7,0,1,2};
  //vector<int> myarr1 {4,5,6,7,0,1,2};
  int target = 0;

  
  int ans = search(myarr1, target); 
  cout << ans << endl;
  return 0;
}




//minmised the step as both the condition doing the same operation

#include <iostream>
#include <vector>

using namespace std;

int search(vector<int>& nums, int target) {
    int l=0,r=nums.size()-1;
    int mid;
    while(l<=r){
        mid = ((l+r)/2);
        if(target == nums[mid]){
            return mid;
        }
        
        //left side
        if(nums[l]<=nums[mid]){
            if(target< nums[l] || target > nums[mid]){
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        //right side
        else{
            if (target>nums[r] || target < nums[mid]){
                r = mid-1;
            }else{
                l=mid+1;
            }
        }
    }
    return -1;   
}
int main()
{
  
  vector<int> myarr1 {4,5,6,7,0,1,2};
  //vector<int> myarr1 {4,5,6,7,0,1,2};
  int target = 0;

  
  int ans = search(myarr1, target); 
  cout << ans << endl;
  return 0;
}
