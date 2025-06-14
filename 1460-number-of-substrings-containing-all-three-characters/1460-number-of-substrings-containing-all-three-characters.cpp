class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        int count = 0;
        int left = 0;
        vector<int> freq(3, 0); // For 'a', 'b', 'c'

        for (int right = 0; right < n; ++right) {
            freq[s[right] - 'a']++;

            // While we have at least one of each character
            while (freq[0] > 0 && freq[1] > 0 && freq[2] > 0) {
                count += n - right; // All substrings starting from 'left' to 'n-1' are valid
                freq[s[left] - 'a']--;
                left++;
            }
        }

        return count;
    }
};
