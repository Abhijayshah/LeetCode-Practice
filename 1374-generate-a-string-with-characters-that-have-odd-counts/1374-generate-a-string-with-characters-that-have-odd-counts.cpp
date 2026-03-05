class Solution {
public:
    string generateTheString(int n) {
        
        // If n is odd
        // We can use the same character n times (odd count)
        if (n % 2 == 1) {
            return string(n, 'a'); // Create string of 'a' repeated n times
        }
        
        // If n is even
        // Use (n-1) times 'a' and 1 time 'b'
        // Both counts remain odd
        return string(n - 1, 'a') + "b";
    }
};