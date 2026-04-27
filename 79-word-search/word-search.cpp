class Solution {
public:
    bool helper(vector<vector<char>>&board, int m, int n, int i, int j, int ind, string word){
        
        if(ind == word.size()){
            return true;
        }

        if((i<0 ||j<0 ||i>=m || j>=n) || word[ind]!=board[i][j])return false;

        char temp = board[i][j];
        board[i][j] = '*';//mark visited

        bool found = helper(board, m, n, i+1,j,ind+1,word)||
                     helper(board, m, n, i-1,j,ind+1,word)||
                     helper(board, m, n, i,j+1,ind+1,word)||
                     helper(board, m, n, i,j-1,ind+1,word);

        board[i][j]= temp;

        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(helper(board,m,n,i,j,0,word)){
                    return true;
                }
            }
        }
        return false;
    }
};