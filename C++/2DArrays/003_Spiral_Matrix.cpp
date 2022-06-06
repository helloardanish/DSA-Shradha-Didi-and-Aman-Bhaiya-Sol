// Spiral Matrix

/*

https://leetcode.com/problems/spiral-matrix/

*/


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int left = 0;
        int right = matrix[0].size()-1;
        int top = 0;
        int bottom = matrix.size()-1;
        vector<int> res;
        int i;
        while(left <= right and top <= bottom) {
            // traverse from left to right in the top row
            for(i = left; i <= right; i++) {
                res.push_back(matrix[top][i]);
            }
            // now that top row is done,decrement the top pointer
            top++;
            // traverse from top to bottom in the rightmost column
            for(i = top; i <= bottom; i++) {
                res.push_back(matrix[i][right]);
            }
            right--;
            if(left > right || top > bottom) break;
            // traverse from right to left in the bottom row
            for(i = right; i >= left; i--) {
                res.push_back(matrix[bottom][i]);
            }
            bottom--;
            // // traverse from bottom to top in the left most column
            for(i=bottom; i >= top; i--) {
                res.push_back(matrix[i][left]);
            }
            left++;
        }
        
        return res;
    }
};
