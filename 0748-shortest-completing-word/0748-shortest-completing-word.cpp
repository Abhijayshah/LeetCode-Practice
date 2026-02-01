class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        vector<int> plateFreq(26, 0); // Frequency array for letters in licensePlate
        
        // Count frequency of letters in licensePlate (ignore numbers, spaces, case-insensitive)
        for (char c : licensePlate) {
            if (isalpha(c)) { // Check if character is a letter
                plateFreq[tolower(c) - 'a']++; // Convert to lowercase and increment frequency
            }
        }
        
        string result = ""; // Store the shortest completing word
        int minLength = INT_MAX; // Track minimum length found
        
        // Check each word in words array
        for (string& word : words) {
            if (isCompletingWord(word, plateFreq)) { // Check if word completes licensePlate
                if (word.length() < minLength) { // If shorter than current result
                    minLength = word.length(); // Update minimum length
                    result = word; // Update result
                }
            }
        }
        
        return result; // Return shortest completing word
    }
    
private:
    bool isCompletingWord(string& word, vector<int>& plateFreq) {
        vector<int> wordFreq(26, 0); // Frequency array for letters in word
        
        for (char c : word) { // Count frequency of each letter in word
            wordFreq[c - 'a']++; // Increment frequency
        }
        
        // Check if word contains all letters from licensePlate with required frequency
        for (int i = 0; i < 26; i++) {
            if (wordFreq[i] < plateFreq[i]) { // If word has fewer of this letter than needed
                return false; // Not a completing word
            }
        }
        
        return true; // Word contains all required letters
    }
};