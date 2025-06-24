class Solution {
public:
    string decodeString(string s) {
        stack<int> countStack;
        stack<string> stringStack;
        string currentStr = "";
        int k = 0;

        for (char ch : s) {
            if (isdigit(ch)) {
                k = k * 10 + (ch - '0'); // Handle multi-digit numbers
            } 
            else if (ch == '[') {
                countStack.push(k);
                stringStack.push(currentStr);
                k = 0;
                currentStr = "";
            } 
            else if (ch == ']') {
                int count = countStack.top(); countStack.pop();
                string prevStr = stringStack.top(); stringStack.pop();

                string decoded = "";
                for (int i = 0; i < count; ++i)
                    decoded += currentStr;

                currentStr = prevStr + decoded;
            } 
            else {
                currentStr += ch;
            }
        }

        return currentStr;
    }
};
