class Solution {
public:
    // Check the boundary cases of the board.
    bool isSafe(int N, int M, int i, int j){
        return (i<N) && (i>=0) && (j>=0) && (j<M);
    }
    bool backtrack(vector<vector<char>>& board, string& word, int pos, int i, int j){
        if(word[pos]!=board[i][j]){
            return false;
        }
        if(pos==word.length()-1){
            return true;
        }
		// to avoid using of this character again in the backtracking
        board[i][j] = '#';
        if(isSafe(board.size(), board[0].size(), i+1, j)){
            if(backtrack(board, word, pos+1, i+1, j))
                return true;
        }
        if(isSafe(board.size(), board[0].size(), i-1, j)){
            if(backtrack(board, word, pos+1, i-1, j))
                return true;
        }
        if(isSafe(board.size(), board[0].size(), i, j+1)){
            if(backtrack(board, word, pos+1, i, j+1))
                return true;
        }
        if(isSafe(board.size(), board[0].size(), i, j-1)){
            if(backtrack(board, word, pos+1, i, j-1))
                return true;
        }
		// Reassigning the character as backtracking is complete.
        board[i][j] = word[pos];
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                if(board[i][j]==word[0])   // This condition is not necessary as it will also be checked in the backtracking function.
                    if(backtrack(board, word, 0, i, j))
                        return true;
            }
        }
        return false;
    }
};
