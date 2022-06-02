// Zigzag (or diagonal) traversal of Matrix


/*

https://www.geeksforgeeks.org/zigzag-or-diagonal-traversal-of-matrix/

*/



#include <iostream>
#include <iomanip>



using namespace std;

#define ROW 5
#define COL 4

int minu(int a, int b){
  return (a<b) ? a:b;
}


int min(int a, int b, int c){
  return minu(minu(a,b),c);
}

void diagonalOrder(int matrix[][COL])
{
     
    // There will be ROW+COL-1 lines
    // in the output
    for(int line = 1;
            line <= (ROW + COL - 1);
            line++)
    {
         
        /* Get column index of the first element
           in this line of output.
           The index is 0 for first ROW lines and
           line - ROW for remaining lines  */
        int start_col =  max(0, line - ROW);
 
        /* Get count of elements in this line. The
           count of elements is equal to minimum of
           line number, COL-start_col and ROW */
         int count = min(line, (COL - start_col), ROW);
 
        /* Print elements of this line */
        for(int j = 0; j < count; j++)
            cout << setw(5) <<
            matrix[minu(ROW, line) - j - 1][start_col + j];
 
        /* Print elements of next
           diagonal on next line */
        cout << "\n";
    }
}



void printMatrix(int matrix[ROW][COL])
{
    for(int i = 0; i < ROW; i++)
    {
        for(int j = 0; j < COL; j++)
            cout << setw(5) << matrix[i][j];
             
        cout << "\n";
    }
}



int main()
{
    int M[ROW][COL] = { { 1, 2, 3, 4 },
                        { 5, 6, 7, 8 },
                        { 9, 10, 11, 12 },
                        { 13, 14, 15, 16 },
                        { 17, 18, 19, 20 },};
    cout << "Given matrix is " << endl;
    printMatrix(M);
 
    cout << "\nDiagonal printing of matrix is " << endl;
    diagonalOrder(M);
    return 0;
}




// Here I made the simplest program for you beginners to understand easily




#include <iostream>
#include <iomanip>
#include <vector>



using namespace std;

void printMatrix(vector<vector<int>> matrix)
{
  int row = matrix.size();
  int col = matrix[0].size();

  //int noofdiagonal = row+col-1; 
  //because one diagonal appears two times
  // from starting row and ending column

  //diagonal upwards formulae is i-1 and j+1

  // first half from top

  for(int i=0; i<row; i++){
    int currrow = i;
    int currcol = 0;

    while(currrow>=0 && currcol<col){
      cout << matrix[currrow][currcol] << " ";
      currrow--;
      currcol++;
    }
    cout <<endl;
  }


  // other half from bottom
  for(int i=1; i<=col-1; i++){
    int currrow = row-1;
    int currcol = i;

    while(currrow>=0 && currcol<col){
      cout << matrix[currrow][currcol] << " ";
      currrow--;
      currcol++;
    }
    cout << endl;
  }
  
}



int main()
{
    vector<vector<int>> M = { { 1, 2, 3, 4 },
                              { 5, 6, 7, 8 },
                              { 9, 10, 11, 12 },
                              { 13, 14, 15, 16 },
                              { 17, 18, 19, 20 },};
    printMatrix(M);
 
    
    return 0;
}



/*

Output


1 
5 2 
9 6 3 
13 10 7 4 
17 14 11 8 
18 15 12 
19 16 
20 


*/
