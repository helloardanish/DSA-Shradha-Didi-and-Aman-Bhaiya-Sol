// Rotate Image

/*

https://leetcode.com/problems/rotate-image/

*/



// Using extra memory is very easy

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        if(matrix.size()==0){
            return;
        }
        
        int n = matrix.size();
        
        vector<vector<int>> ansmat(n, vector(n,0));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                ansmat[i][j] = matrix[n-1-j][i];
            }
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                matrix[i][j] = ansmat[i][j];
            }
        }
        
    }
};








// In place solution



class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        if(matrix.size()==0){
            return;
        }
        
        int n = matrix.size();
        
        
        for(int i=0; i<(n+1)/2; i++){
            for(int j=0; j<n/2; j++){
                
                int temp = matrix[n-1-j][i];
                matrix[n-1-j][i] = matrix[n-i-1][n-j-1];
                matrix[n-i-1][n-j-1] = matrix[j][n-1-i];
                matrix[j][n-1-i] = matrix[i][j];
                
                matrix[i][j] = temp;
            }
        }
    }
};
