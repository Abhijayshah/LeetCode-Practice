class Solution {
public:
    
    // Function to calculate nCr using factorial
    int nCr(int n, int r) {
        long long res = 1;                // Store result

        for (int i = 0; i < r; i++) {     // Compute nCr iteratively
            res = res * (n - i) / (i + 1);
        }

        return res;                       // Return combination value
    }

    vector<vector<int>> generate(int numRows) {

        vector<vector<int>> triangle;    // Store Pascal's triangle

        for (int i = 0; i < numRows; i++) {     // Loop for each row
            vector<int> row;

            for (int j = 0; j <= i; j++) {      // Loop for each element in row
                row.push_back(nCr(i, j));       // Compute value using nCr
            }

            triangle.push_back(row);            // Add row to triangle
        }

        return triangle;                         // Return result
    }
};

