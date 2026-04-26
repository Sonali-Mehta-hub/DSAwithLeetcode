class Solution {
public:
    bool helper(vector<vector<char>>&board, int i, int j, int m, int n, string word, int ind){
        if(ind == word.size()){
            return true;
        }

       if(( i < 0 ||j < 0 || i >= m || j >= n ) || board[i][j]!= word[ind])return false;

       char temp = board[i][j];
       board[i][j]='#'; //mark visited

       bool found = helper(board, i+1, j, m, n, word, ind+1) || 
                    helper(board, i-1, j, m, n, word, ind+1) ||
                    helper(board, i, j+1, m, n, word, ind+1) ||
                    helper(board, i, j-1, m, n, word, ind+1) ;

        board[i][j] = temp; // backtrack

        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        for(int i = 0; i<m ; i++){
            for(int j = 0; j<n ; j++){
                if(helper(board, i, j, m, n, word, 0)){
                    return  true;
                }
                
            }
        }

        return false;
    }
};