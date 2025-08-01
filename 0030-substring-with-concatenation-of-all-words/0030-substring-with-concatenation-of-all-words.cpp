class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (words.empty() || s.empty()) return result;

        int wordLen = words[0].size();
        int wordCount = words.size();
        int totalLen = wordLen * wordCount;

        if (s.size() < totalLen) return result;

        unordered_map<string, int> wordFreq;
        for (const string& word : words) {
            wordFreq[word]++;
        }

        // Try each possible offset
        for (int i = 0; i < wordLen; i++) {
            int left = i, right = i, count = 0;
            unordered_map<string, int> seen;

            while (right + wordLen <= s.size()) {
                string word = s.substr(right, wordLen);
                right += wordLen;

                if (wordFreq.find(word) != wordFreq.end()) {
                    seen[word]++;
                    count++;

                    // If word seen too many times, move the window from left
                    while (seen[word] > wordFreq[word]) {
                        string leftWord = s.substr(left, wordLen);
                        seen[leftWord]--;
                        left += wordLen;
                        count--;
                    }

                    // If we have all words matched
                    if (count == wordCount) {
                        result.push_back(left);
                    }
                } else {
                    // Reset window
                    seen.clear();
                    count = 0;
                    left = right;
                }
            }
        }

        return result;
    }
};
