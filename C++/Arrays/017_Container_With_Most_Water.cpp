/*

https://leetcode.com/problems/container-with-most-water/

*/


// using two pointers it can easily be solved

class Solution {
public:
    int maxArea(vector<int>& height) {
        int max=-1;
        int l=0, r=height.size()-1;
        
        while(l<=r){
            int val = min(height[l], height[r])*(r-l);
            if(max<val){
                max=val;
            }
            if(height[l]<height[r]){
                ++l;
            }else{
                --r;
            }
        }
        return max;
    }
};



// I implemented below solution but its not correct as it will fail for few cases.
class Solution {
public:
    int maxArea(vector<int>& height) {
        int max=-1;
        int lastmaxindex=0;
        
        for(int i=1; i<height.size(); i++){
            int val = min(height[i], height[lastmaxindex])*(i-lastmaxindex);
            if(max<val){
                max=val;
            }
            if(height[i]>height[lastmaxindex]){
                lastmaxindex=i;
            }
        }
        return max;
    }
};
