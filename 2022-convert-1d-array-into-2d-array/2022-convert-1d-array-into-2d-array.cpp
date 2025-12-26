class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {

        // Step 1: Check if conversion is possible
        if (original.size() != m * n)
            return {};   // return empty 2D array

        // Step 2: Create result 2D array with m rows and n columns
        vector<vector<int>> result(m, vector<int>(n));

        // Step 3: Fill the 2D array using index mapping
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                result[i][j] = original[i * n + j];
            }
        }

        return result;
    }
};
