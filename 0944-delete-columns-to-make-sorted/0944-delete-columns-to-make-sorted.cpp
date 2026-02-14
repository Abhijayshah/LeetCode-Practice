class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        if (strs.empty()) return 0;
        
        int rows = strs.size();
        int cols = strs[0].size();
        int deleteCount = 0;
        
        // Check each column
        for (int j = 0; j < cols; j++) {
            // Check if this column is sorted
            for (int i = 1; i < rows; i++) {
                // If current character is smaller than previous in same column
                if (strs[i][j] < strs[i-1][j]) {
                    deleteCount++;
                    break;  // No need to check further in this column
                }
            }
        }
        
        return deleteCount;
    }
};