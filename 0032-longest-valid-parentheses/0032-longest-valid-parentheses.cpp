class Solution {
public:
    int longestValidParentheses(string s) {
        int maxLen = 0;
        int n = s.size();
        stack<int> stk;
        stk.push(-1); // Base for valid substring

        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                stk.push(i);
            } else {
                stk.pop();
                if (stk.empty()) {
                    stk.push(i);
                } else {
                    maxLen = max(maxLen, i - stk.top());
                }
            }
        }
        return maxLen;
    }
};
