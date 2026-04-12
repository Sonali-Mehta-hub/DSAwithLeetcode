class Solution {
public:
// optimal solution hash set
void solve(int col, int n, vector<string>&board, vector<vector<string>>&ans, vector<int>&leftRow, vector<int>& upperDiag, vector<int>& lowerDiag){
    if(col==n){
        ans.push_back(board);
        return ;
    }
    
    for(int row=0;row<n;row++){

         if(leftRow[row]==0 && upperDiag[(n-1)+(col-row)]==0 &&  lowerDiag[row+col]==0){
            board[row][col]='Q';
            leftRow[row]=1;
            upperDiag[(n-1)+(col-row)]=1;
            lowerDiag[row+col]=1;

            solve(col+1,n,board,ans,leftRow,upperDiag,lowerDiag);

            board[row][col]='.';
            leftRow[row]=0;
            upperDiag[(n-1)+(col-row)]=0;
            lowerDiag[row+col]=0;
        
        }
    }
}
vector<vector<string>> solveNQueens(int n) {
       vector<string>board(n);
       vector<vector<string>>ans;
       string s(n,'.');

       for(int i=0; i<n;i++){
         board[i]=s;
       }

     vector<int>leftRow(n,0),upperDiag(2*n-1,0),lowerDiag(2*n-1);
    solve(0, n, board, ans, leftRow, upperDiag,lowerDiag);
    return ans;
    }
};


//time complexity O(n)+O(n)+O(n) for is it it safe of not
//     bool isSafe(int row, int col, int n, vector<string> &board){
//         int temprow = row;
//         int tempcol = col;

//        //for upper diagonal
//        while(row>=0 && col>=0){
//         if(board[row][col]=='Q')return false;
//         row--;
//         col--;
//        }

//        //for previous column
       
//        row= temprow;
//        col= tempcol;

//        while(col>=0){
//         if(board[row][col]=='Q')return false;
//         col--;
//        }

//        //lower diagonal

//        row = temprow;
//        col = tempcol;
//        while(row<n && col>=0){
//         if(board[row][col]=='Q'){
//             return false;
//         }
//         row++;
//         col--;
//        }
//        return true;
//     }
//     void solve(int col, int n, vector<string>&board, vector<vector<string>>&ans){
//        if(col==n){
//         ans.push_back(board);
//         return;
//        }

//         for(int row=0;row<n;row++){
//             if(isSafe(row, col, n, board)){
//                 board[row][col]='Q';
//                 solve(col+1,n, board, ans );
//                 board[row][col]='.';
//             }
//         }
//     }
//     vector<vector<string>> solveNQueens(int n) {
//        vector<string>board(n);
//        vector<vector<string>>ans;
//        string s(n,'.');

//        for(int i=0; i<n;i++){
//          board[i]=s;
//        }
//     solve(0, n, board, ans);
//     return ans;
//     }
// };