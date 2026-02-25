class Solution {
public:
    string freqAlphabets(string s) {
        
        string result = ""; // Store final decoded string
        
        for (int i = 0; i < s.length(); i++) {
            
            // Check if we have a pattern like "10#" to "26#"
            if (i + 2 < s.length() && s[i + 2] == '#') {
                
                // Extract two-digit number
                int num = (s[i] - '0') * 10 + (s[i + 1] - '0');
                
                // Convert to corresponding character
                result += char('a' + num - 1);
                
                i += 2; // Skip next two characters ('digit' and '#')
            }
            else {
                
                // Single digit mapping ('1' to '9')
                int num = s[i] - '0';
                
                result += char('a' + num - 1);
            }
        }
        
        return result; // Return decoded string
    }
};