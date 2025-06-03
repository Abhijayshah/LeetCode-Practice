class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.length() - 1;
        // Skip trailing spaces
        while (i >= 0 && s[i] == ' ') {
            i--;
        }
        // Count characters of the last word
        int count = 0;
        while (i >= 0 && s[i] != ' ') {
            count++;
            i--;
        }
        return count;
    }
};
