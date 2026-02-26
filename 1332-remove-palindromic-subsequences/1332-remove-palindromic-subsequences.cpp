class Solution {
public:
    int removePalindromeSub(string s) {
        
        // If string is empty
        if (s.length() == 0)
            return 0;
        
        int left = 0;                      // Left pointer
        int right = s.length() - 1;        // Right pointer
        
        // Check if entire string is palindrome
        while (left < right) {
            
            if (s[left] != s[right]) {
                return 2; // Not palindrome → need 2 steps
            }
            
            left++;   // Move left forward
            right--;  // Move right backward
        }
        
        // If palindrome, remove in one step
        return 1;
    }
};