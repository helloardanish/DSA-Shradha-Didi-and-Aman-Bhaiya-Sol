/*
https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0, r=nums.size()-1;
        int mid;
        
        if(nums.size()==1){
            return nums[0];
        }
        
        
        // if array is sorted, first element is the smallest
        if(nums[0] < nums[r]){
            return nums[0];
        }
        
        
        while(l<=r){
            mid = (l+r)/2;
            if(nums[mid] >nums[mid+1]){
                return nums[mid+1];
            }
            
            if(nums[mid-1]>nums[mid]){
                return nums[mid];
            }
            
            if(nums[0]<nums[mid]){
                l = mid+1;
            }else{
                r = mid-1;
            }
        }
        return -1;
    }
};
