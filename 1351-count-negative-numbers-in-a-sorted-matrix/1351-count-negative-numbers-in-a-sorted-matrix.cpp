class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {

        int count = 0;                           // Store count of negatives

        for (int i = 0; i < grid.size(); i++) { // Loop through rows
            for (int j = 0; j < grid[0].size(); j++) { // Loop through columns
                if (grid[i][j] < 0) {            // Check if element is negative
                    count++;                     // Increment count
                }
            }
        }

        return count;                            // Return total negatives
    }
};
