class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n = s.length(); // Get length of string
        int low = 0, high = n; // Initialize two pointers: low starts at 0, high at n
        vector<int> result; // Vector to store the permutation
        
        for (int i = 0; i < n; i++) { // Iterate through each character in string
            if (s[i] == 'I') { // If 'I' (Increasing), use smallest available number
                result.push_back(low); // Add low to result
                low++; // Increment low for next smallest
            } else { // If 'D' (Decreasing), use largest available number
                result.push_back(high); // Add high to result
                high--; // Decrement high for next largest
            }
        }
        
        result.push_back(low); // Add the last remaining number (low == high at this point)
        return result; // Return the permutation
    }
};