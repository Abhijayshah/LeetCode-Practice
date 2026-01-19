class Solution {
public:
    int findLUSlength(string a, string b) {

        // If both strings are exactly the same
        if (a == b)
            return -1;

        // Otherwise, the longer string itself
        // is the longest uncommon subsequence
        return max(a.length(), b.length());
    }
};
