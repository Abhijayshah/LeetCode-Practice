class Solution {
public:
    int calculate(string s) {
        int result = 0, sign = 1, n = s.size();
        stack<int> stk;
        int i = 0;
        while (i < n) {
            if (isdigit(s[i])) {
                int num = 0;
                while (i < n && isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                result += sign * num;
                continue; // already incremented i in the inner loop
            } else if (s[i] == '+') {
                sign = 1;
            } else if (s[i] == '-') {
                sign = -1;
            } else if (s[i] == '(') {
                stk.push(result);
                stk.push(sign);
                result = 0;
                sign = 1;
            } else if (s[i] == ')') {
                int prevSign = stk.top(); stk.pop();
                int prevResult = stk.top(); stk.pop();
                result = prevResult + prevSign * result;
            }
            i++;
        }
        return result;
    }
};
