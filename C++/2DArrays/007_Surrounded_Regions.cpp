// Surrounded Regions


/*

https://www.geeksforgeeks.org/given-matrix-o-x-replace-o-x-surrounded-x/


https://leetcode.com/problems/surrounded-regions/

*/


/* Idea:


The Idea is first to Mark those grid which having value ' O ' are deeply adjacent to the First Row , First Column , Last Row and Last Column !!!
so we are going to update those grid by changeing it's value ' O' - > ' P ' [ I am use ' P ' here ,but You can chose any Value except ' X ' and ' O ' ]
To make it happend we run DFS from the Borders[ each by one ] Of The board
That's It ! this is The main Work , and we done it !!!! [ YES ]

now the remaining grid those having ' O ' value is the grid which we looking for to change from ' O ' - > ' X '
do that change and the Other grid which we update as value ' P ' need to make them ' O ' again

*/


class Solution {
public:
    void DFS(vector<vector<char>>& board,int r,int c,int rsize,int csize){
        if(r<0||c<0||r==rsize||c==csize||board[r][c]!='O')return;
        board[r][c] = 'P';
        DFS(board,r+1,c,rsize,csize);
        DFS(board,r,c+1,rsize,csize);
        DFS(board,r-1,c,rsize,csize);
        DFS(board,r,c-1,rsize,csize);
    }
    void solve(vector<vector<char>>& board) {
        if(board.empty())return;
        int row = board.size(),col = board[0].size();
        for(int i=0;i<col;i++)DFS(board,0,i,row,col),DFS(board,row-1,i,row,col); // first row and last row
        for(int i=0;i<row;i++)DFS(board,i,0,row,col),DFS(board,i,col-1,row,col); //first column and last column
        
        for(int i=0;i<row;i++)
            for(int j=0;j<col;j++)
                if(board[i][j]=='O')board[i][j]='X';
                else if(board[i][j]=='P')board[i][j]='O';
    }
};






// Same logic



public:
    void solve(vector<vector<char>>& board) {
        if (board.empty()) return;
        int row = board.size(), col = board[0].size();
        for (int i = 0; i < row; ++i) {
            check(board, i, 0);             // first column
            check(board, i, col - 1);       // last column
        }
        for (int j = 1; j < col - 1; ++j) {
            check(board, 0, j);             // first row
            check(board, row - 1, j);       // last row
        }
        for (int i = 0; i < row; ++i)
            for (int j = 0; j < col; ++j)
                if (board[i][j] == 'O') board[i][j] = 'X';
                else if (board[i][j] == '1') board[i][j] = 'O';
    }
    
    void check(vector<vector<char>>& board, int i, int j) {
        if (board[i][j] == 'O') {
            board[i][j] = '1';
            if (i > 1) check(board, i - 1, j);
            if (j > 1) check(board, i, j - 1);
            if (i + 1 < board.size()) check(board, i + 1, j);
            if (j + 1 < board[0].size()) check(board, i, j + 1);
        }
    }
};
