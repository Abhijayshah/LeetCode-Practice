class Solution {
public:
    bool wordPattern(string pattern, string s) {

        vector<string> words;              // Store words from s
        string temp = "";

        // Step 1: Split s into words
        for (char c : s) {
            if (c == ' ') {
                words.push_back(temp);
                temp = "";
            } else {
                temp += c;
            }
        }
        words.push_back(temp);             // Add last word

        // Step 2: Length mismatch check
        if (pattern.length() != words.size())
            return false;

        unordered_map<char, string> mp1;   // char → word
        unordered_map<string, char> mp2;   // word → char

        // Step 3: Traverse pattern & words
        for (int i = 0; i < pattern.length(); i++) {

            char ch = pattern[i];
            string word = words[i];

            // If character already mapped
            if (mp1.count(ch)) {
                if (mp1[ch] != word)
                    return false;
            } 
            // If word already mapped
            else if (mp2.count(word)) {
                if (mp2[word] != ch)
                    return false;
            }
            // New mapping
            else {
                mp1[ch] = word;
                mp2[word] = ch;
            }
        }
        return true;
    }
};
