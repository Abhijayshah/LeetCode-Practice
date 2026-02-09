// ## Question in Short (5 lines)

// **Problem:** Find words that appear exactly once across two sentences combined and don't appear in both sentences.

// **Uncommon Word:** A word that appears exactly once total in either s1 or s2 (not in both).

// **Task:** Return all uncommon words from both sentences in any order.

// **Examples:** s1="this apple is sweet", s2="this apple is sour" → ["sweet","sour"] (both appear once, others repeat)

// **Approach:** Count frequency of all words in both sentences, return words with frequency = 1.

// ---

// ## Solution with Comments

// ```cpp
class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> wordCount; // Map to store word frequency
        vector<string> result; // Vector to store uncommon words
        
        string combined = s1 + " " + s2; // Combine both sentences with space
        stringstream ss(combined); // Create string stream to split words
        string word; // Temporary variable to store each word
        
        while (ss >> word) { // Extract each word from stream
            wordCount[word]++; // Increment frequency count for this word
        }
        
        for (auto& pair : wordCount) { // Loop through all word-frequency pairs
            if (pair.second == 1) { // If word appears exactly once
                result.push_back(pair.first); // Add word to result
            }
        }
        
        return result; // Return all uncommon words
    }
};
// ```

// **Alternative Solution (Separate Processing):**

// ```cpp
// class Solution {
// public:
//     vector<string> uncommonFromSentences(string s1, string s2) {
//         unordered_map<string, int> wordCount; // Map to count word frequencies
//         vector<string> result; // Store final uncommon words
        
//         // Process first sentence
//         stringstream ss1(s1); // Create stream for s1
//         string word; // Temporary word variable
//         while (ss1 >> word) { // Extract each word from s1
//             wordCount[word]++; // Increment count for word
//         }
        
//         // Process second sentence
//         stringstream ss2(s2); // Create stream for s2
//         while (ss2 >> word) { // Extract each word from s2
//             wordCount[word]++; // Increment count for word
//         }
        
//         // Collect words with frequency 1
//         for (auto& [w, freq] : wordCount) { // Iterate through map
//             if (freq == 1) { // If word appears exactly once total
//                 result.push_back(w); // Add to result
//             }
//         }
        
//         return result; // Return uncommon words
//     }
// };
// ```

// **How it works:**
// 1. Combine both sentences into one string
// 2. Use stringstream to split by spaces and count word frequencies
// 3. Find words with frequency = 1 (appear only once across both sentences)
// 4. Return those words

// **Key Insight:** Uncommon = appears exactly once total (not once per sentence)

// **Time Complexity:** O(n + m) - where n, m are lengths of s1, s2  
// **Space Complexity:** O(n + m) - for storing words in hashmap