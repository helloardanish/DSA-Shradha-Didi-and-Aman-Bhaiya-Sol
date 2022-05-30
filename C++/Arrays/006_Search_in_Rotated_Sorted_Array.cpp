// Search in Rotated Sorted Array


/*

https://www.geeksforgeeks.org/search-an-element-in-a-sorted-and-pivoted-array/


https://leetcode.com/problems/search-in-rotated-sorted-array/

*/


class Solution {
public:
    int search(vector<int>& nums, int target) {
          int s=0;
          int e = nums.size()-1;
          while(s<=e){
            int mid=s+(e-s)/2;
            if(nums[mid]==target){
              return mid;
            }else if(nums[mid] >= nums[s]){
              if(target >= nums[s] && target <= nums[mid]){
                e=mid-1;
              }else{
                s=mid+1;
              }
            }else if(nums[mid] < nums[e]){
              if(target >= nums[mid] && target <= nums[e]){
                s = mid+1;
              }else{
                e = mid-1;
              }
            }
          }
          return -1;
    }
};
