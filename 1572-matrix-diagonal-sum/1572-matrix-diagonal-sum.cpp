class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int sum = 0;
        
        for (int i = 0; i < n; i++) {
            // Add primary diagonal element
            sum += mat[i][i];
            
            // Add secondary diagonal element
            sum += mat[i][n - 1 - i];
        }
        
        // If n is odd, subtract the center element (counted twice)
        if (n % 2 == 1) {
            sum -= mat[n / 2][n / 2];
        }
        
        return sum;
    }
};