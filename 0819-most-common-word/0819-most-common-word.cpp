class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {

        unordered_set<string> bannedSet(banned.begin(), banned.end());
        unordered_map<string, int> freq;

        string word = "";
        for (int i = 0; i <= paragraph.size(); i++) {

            if (i < paragraph.size() && isalpha(paragraph[i])) {
                word += tolower(paragraph[i]);
            } else {
                if (!word.empty()) {
                    if (bannedSet.find(word) == bannedSet.end()) {
                        freq[word]++;
                    }
                    word.clear();
                }
            }
        }

        string answer = "";
        int maxCount = 0;

        for (auto &p : freq) {
            if (p.second > maxCount) {
                maxCount = p.second;
                answer = p.first;
            }
        }

        return answer;
    }
};
