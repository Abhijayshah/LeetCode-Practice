class Solution {
public:
    string sortString(string s) {
        
        vector<int> freq(26, 0); // Frequency array for characters a-z
        
        // Count frequency of each character
        for (char c : s) {
            freq[c - 'a']++; // Increment corresponding frequency
        }
        
        string result = ""; // Store final reordered string
        
        int n = s.length(); // Total characters
        
        while (result.length() < n) { // Continue until all characters used
            
            // Step 1: Pick characters in increasing order
            for (int i = 0; i < 26; i++) {
                
                if (freq[i] > 0) { // If character exists
                    
                    result += char('a' + i); // Append smallest available
                    freq[i]--;               // Decrease frequency
                }
            }
            
            // Step 2: Pick characters in decreasing order
            for (int i = 25; i >= 0; i--) {
                
                if (freq[i] > 0) { // If character exists
                    
                    result += char('a' + i); // Append largest available
                    freq[i]--;               // Decrease frequency
                }
            }
        }
        
        return result; // Return final reordered string
    }
};