class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.size();
        string result;
        int open = 0;

        // First pass: Remove invalid ')'
        for (char c : s) {
            if (c == '(') {
                open++;
                result += c;
            } else if (c == ')') {
                if (open > 0) {
                    open--;
                    result += c;
                }
                // else: skip this ')'
            } else {
                result += c;
            }
        }

        // Second pass: Remove extra '(' from right to left
        string finalResult;
        int close = 0;
        for (int i = result.size() - 1; i >= 0; --i) {
            if (result[i] == '(' && open > 0) {
                open--;
                // skip this '('
            } else {
                finalResult += result[i];
            }
        }
        reverse(finalResult.begin(), finalResult.end());
        return finalResult;
    }
};
