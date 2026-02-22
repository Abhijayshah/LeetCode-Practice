class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        
        vector<int> baseFreq(26, 0); // Store frequency of characters in chars
        
        // Count frequency of each character in chars
        for (char ch : chars) {
            baseFreq[ch - 'a']++;
        }
        
        int totalLength = 0; // Store sum of lengths of good words
        
        // Check each word
        for (string word : words) {
            
            vector<int> wordFreq(26, 0); // Frequency for current word
            bool isGood = true;          // Flag to check if word can be formed
            
            // Count frequency of characters in current word
            for (char ch : word) {
                wordFreq[ch - 'a']++;
                
                // If frequency exceeds available chars, word is invalid
                if (wordFreq[ch - 'a'] > baseFreq[ch - 'a']) {
                    isGood = false;
                    break;
                }
            }
            
            // If word can be formed, add its length
            if (isGood) {
                totalLength += word.length();
            }
        }
        
        return totalLength; // Return total length of good words
    }
};