class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> board(n, string(n, '.'));
        backtrack(result, board, 0, n);
        return result;
    }
    
private:
    void backtrack(vector<vector<string>>& result, vector<string>& board, int row, int n) {
        // Base case: if we've placed all queens successfully
        if (row == n) {
            result.push_back(board);
            return;
        }
        
        // Try placing a queen in each column of the current row
        for (int col = 0; col < n; col++) {
            if (isSafe(board, row, col, n)) {
                // Place the queen
                board[row][col] = 'Q';
                
                // Recursively place queens in the next row
                backtrack(result, board, row + 1, n);
                
                // Backtrack: remove the queen
                board[row][col] = '.';
            }
        }
    }
    
    bool isSafe(vector<string>& board, int row, int col, int n) {
        // Check column (no need to check rows below current row as we haven't placed queens there yet)
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q') {
                return false;
            }
        }
        
        // Check upper-left diagonal
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }
        
        // Check upper-right diagonal
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }
        
        return true;
    }
};