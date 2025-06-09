class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        // Start with the first string as the prefix
        string prefix = strs[0];

        // Compare the prefix with every string in the array
        for (int i = 1; i < strs.size(); ++i) {
            // Reduce the prefix until it matches the start of strs[i]
            while (strs[i].find(prefix) != 0) {
                prefix = prefix.substr(0, prefix.length() - 1);
                if (prefix.empty()) return "";
            }
        }

        return prefix;
    }
};
