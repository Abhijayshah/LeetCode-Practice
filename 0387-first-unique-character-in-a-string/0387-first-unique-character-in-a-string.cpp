class Solution {
public:
    int firstUniqChar(string s) {

        // Step 1: Frequency array for 26 lowercase letters
        vector<int> freq(26, 0);

        // Count frequency of each character
        for (char c : s) {
            freq[c - 'a']++;
        }

        // Step 2: Find first character with frequency 1
        for (int i = 0; i < s.size(); i++) {
            if (freq[s[i] - 'a'] == 1) {
                return i;
            }
        }

        // Step 3: No unique character found
        return -1;
    }
};
