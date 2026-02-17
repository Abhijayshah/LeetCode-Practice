class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        
        vector<string> words;   // Store all words from text
        vector<string> result;  // Store final third words
        
        stringstream ss(text);  // Create stringstream to split text
        string word;            // Temporary variable to store each word
        
        // Split text into words
        while (ss >> word) {
            words.push_back(word); // Add each word to vector
        }
        
        // Traverse words and check triplets
        for (int i = 0; i + 2 < words.size(); i++) {
            
            // Check if current pair matches first and second
            if (words[i] == first && words[i + 1] == second) {
                
                result.push_back(words[i + 2]); // Add third word
            }
        }
        
        return result; // Return all matching third words
    }
};
