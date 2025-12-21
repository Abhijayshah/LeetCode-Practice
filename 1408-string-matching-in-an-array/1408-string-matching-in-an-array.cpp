class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> result;
        int n = words.size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // Avoid comparing the same word
                if (i != j && words[j].find(words[i]) != string::npos) {
                    result.push_back(words[i]);
                    break; // No need to check further
                }
            }
        }

        return result;
    }
};
