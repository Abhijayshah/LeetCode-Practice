class Solution {
public:
    string makeSmallestPalindrome(string s) {
        int n = s.length();
        string result = s; // Create a copy of the original string to modify

        for (int i = 0; i < n / 2; i++) {
            // Compare characters from both ends
            char leftChar = result[i];
            char rightChar = result[n - 1 - i];

            // Choose the lexicographically smaller character
            if (leftChar != rightChar) {
                char smallerChar = min(leftChar, rightChar);
                result[i] = smallerChar; // Update the left character
                result[n - 1 - i] = smallerChar; // Update the right character
            }
        }

        return result; // Return the modified string which is now a palindrome
    }
};
