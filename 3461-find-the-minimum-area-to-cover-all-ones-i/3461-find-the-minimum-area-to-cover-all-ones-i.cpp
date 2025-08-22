class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        // Initialize boundaries
        int minRow = rows, maxRow = -1;
        int minCol = cols, maxCol = -1;
        
        // Find the boundaries of all 1's
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    minRow = min(minRow, i);
                    maxRow = max(maxRow, i);
                    minCol = min(minCol, j);
                    maxCol = max(maxCol, j);
                }
            }
        }
        
        // Calculate the area of the rectangle
        int height = maxRow - minRow + 1;
        int width = maxCol - minCol + 1;
        
        return height * width;
    }
};