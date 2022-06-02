// Set Matrix Zeroes

/*

https://leetcode.com/problems/set-matrix-zeroes/

*/


class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set<int> rowset;
        unordered_set<int> colset;
        
        
        int row = matrix.size();
        int col = matrix[0].size();
        
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                int temp = matrix[i][j];
                if(temp==0){
                    if(rowset.find(i) == rowset.end()){
                        rowset.insert(i);
                    }
                    
                    if(colset.find(j) == colset.end()){
                        colset.insert(j);
                    }
                }
            }
        }
        
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(rowset.find(i)!=rowset.end() || colset.find(j)!=colset.end()){
                    matrix[i][j]=0;
                }
            }
        }   
    }
};


