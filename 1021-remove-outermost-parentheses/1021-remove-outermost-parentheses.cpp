class Solution {
public:
    string removeOuterParentheses(string s) {
        
        string result = ""; // Store final modified string
        int depth = 0;      // Track current parentheses nesting depth
        
        for (char ch : s) { // Traverse each character
            
            if (ch == '(') {
                
                // If depth > 0, it is not outermost, so keep it
                if (depth > 0) {
                    result += ch; // Add '(' to result
                }
                
                depth++; // Increase depth after processing '('
            }
            else { // If character is ')'
                
                depth--; // Decrease depth first
                
                // If depth > 0, it is not outermost, so keep it
                if (depth > 0) {
                    result += ch; // Add ')' to result
                }
            }
        }
        
        return result; // Return final string after removal
    }
};
