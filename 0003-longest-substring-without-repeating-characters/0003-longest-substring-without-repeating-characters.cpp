#include <unordered_map>
#include <algorithm>

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if (n <= 1) {
            return n;
        }

        int max_length = 0;
        unordered_map<char, int> char_map;
        int start = 0;

        for (int end = 0; end < n; end++) {
            if (char_map.find(s[end]) != char_map.end() && char_map[s[end]] >= start) {
                start = char_map[s[end]] + 1;
            } else {
                max_length = max(max_length, end - start + 1);
            }
            char_map[s[end]] = end;
        }

        return max_length;
    }
};
