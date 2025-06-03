class Solution {
public:
    int countSegments(string s) {
        int count = 0;
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            // A segment starts when we see a non-space character
            // that is either at the beginning or preceded by a space.
            if (s[i] != ' ' && (i == 0 || s[i - 1] == ' ')) {
                ++count;
            }
        }
        return count;
    }
};
