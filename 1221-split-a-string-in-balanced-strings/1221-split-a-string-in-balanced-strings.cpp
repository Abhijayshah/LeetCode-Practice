class Solution {
public:
    int balancedStringSplit(string s) {
        
        int balance = 0; // Track difference between 'L' and 'R'
        int count = 0;   // Store number of balanced substrings
        
        // Traverse each character in string
        for (char ch : s) {
            
            if (ch == 'L') {
                balance++; // Increment for 'L'
            }
            else {
                balance--; // Decrement for 'R'
            }
            
            // If balance becomes zero, we found a balanced substring
            if (balance == 0) {
                count++; // Increase count
            }
        }
        
        return count; // Return maximum balanced substrings
    }
};