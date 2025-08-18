class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        // Edge case: if start or end has obstacle
        if (obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1) {
            return 0;
        }
        
        // Create DP table
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        // Initialize starting position
        dp[0][0] = 1;
        
        // Fill first row
        for (int j = 1; j < n; j++) {
            if (obstacleGrid[0][j] == 0) {
                dp[0][j] = dp[0][j-1];
            }
            // If obstacle, dp[0][j] remains 0
        }
        
        // Fill first column
        for (int i = 1; i < m; i++) {
            if (obstacleGrid[i][0] == 0) {
                dp[i][0] = dp[i-1][0];
            }
            // If obstacle, dp[i][0] remains 0
        }
        
        // Fill the rest of the DP table
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (obstacleGrid[i][j] == 0) {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
                // If obstacle, dp[i][j] remains 0
            }
        }
        
        return dp[m-1][n-1];
    }
};

// Space-optimized solution using only O(n) space
class SolutionOptimized {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        // Edge case: if start or end has obstacle
        if (obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1) {
            return 0;
        }
        
        // Use 1D DP array representing current row
        vector<int> dp(n, 0);
        dp[0] = 1;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (obstacleGrid[i][j] == 1) {
                    dp[j] = 0;  // Obstacle blocks all paths
                } else if (j > 0) {
                    dp[j] += dp[j-1];  // Add paths from left
                }
                // dp[j] already contains paths from above (previous iteration)
            }
        }
        
        return dp[n-1];
    }
};

// In-place solution modifying the input grid
class SolutionInPlace {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        // Edge case: if start has obstacle
        if (obstacleGrid[0][0] == 1) {
            return 0;
        }
        
        // Convert obstacles (1) to 0 and free spaces (0) to path counts
        obstacleGrid[0][0] = 1;  // Starting position has 1 way to reach
        
        // Initialize first row
        for (int j = 1; j < n; j++) {
            obstacleGrid[0][j] = (obstacleGrid[0][j] == 0 && obstacleGrid[0][j-1] == 1) ? 1 : 0;
        }
        
        // Initialize first column
        for (int i = 1; i < m; i++) {
            obstacleGrid[i][0] = (obstacleGrid[i][0] == 0 && obstacleGrid[i-1][0] == 1) ? 1 : 0;
        }
        
        // Fill the rest
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (obstacleGrid[i][j] == 0) {
                    obstacleGrid[i][j] = obstacleGrid[i-1][j] + obstacleGrid[i][j-1];
                } else {
                    obstacleGrid[i][j] = 0;  // Obstacle
                }
            }
        }
        
        return obstacleGrid[m-1][n-1];
    }
};