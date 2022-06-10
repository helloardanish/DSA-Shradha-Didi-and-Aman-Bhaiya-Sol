// Majority Element


/*

https://www.geeksforgeeks.org/majority-element/

https://leetcode.com/problems/majority-element/

*/


// One way



class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int maxEle = nums[0];
        int maxCount=0;
        for(int i=0; i<nums.size(); i++){
            int count = 0;
            int curr = nums[i];
            for(int j=0; j<nums.size(); j++){
                if(curr==nums[j]){
                    count++;
                    if(count > nums.size()/2){
                        return curr;
                    }
                }
            }
            if(maxCount < count){
                maxCount = count;
                maxEle = curr; 
            }
        }
        return maxEle;
    }
};





// Second way



class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> up;
        
        for(int i=0; i<nums.size(); i++){
            if(up.find(nums[i])==up.end()){
                up[nums[i]] = 1;
            }else{
                up[nums[i]] = up[nums[i]] + 1;
                // up[nums[i]]++
            }
            if(up[nums[i]] > nums.size()/2){
                return nums[i];
            }
        }
        return -1;
    }
};





// Third way


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majEle = nums[0];
        int count = 1;
        for(int i=1; i<nums.size(); i++){
            if(nums[i] == majEle){
                count++;
                if(count > nums.size()/2){
                    return nums[i];
                }
            }else{
                count--;
                if(count==0){
                    majEle = nums[i];
                    count++;
                    // count =1;
                }
            }
        }
        return majEle;
    }
};
