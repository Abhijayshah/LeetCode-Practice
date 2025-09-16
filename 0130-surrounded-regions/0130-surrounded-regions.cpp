#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n, m;

    void dfs(vector<vector<char>>& board, int i, int j) {
        if (i < 0 || j < 0 || i >= n || j >= m || board[i][j] != 'O') 
            return;
        board[i][j] = '#'; // mark as safe
        dfs(board, i + 1, j);
        dfs(board, i - 1, j);
        dfs(board, i, j + 1);
        dfs(board, i, j - 1);
    }

    void solve(vector<vector<char>>& board) {
        n = board.size();
        m = board[0].size();

        // Step 1: DFS from border 'O's
        for (int i = 0; i < n; i++) {
            dfs(board, i, 0);
            dfs(board, i, m - 1);
        }
        for (int j = 0; j < m; j++) {
            dfs(board, 0, j);
            dfs(board, n - 1, j);
        }

        // Step 2: Flip cells
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O') board[i][j] = 'X';  // captured
                else if (board[i][j] == '#') board[i][j] = 'O';  // restore safe
            }
        }
    }
};
