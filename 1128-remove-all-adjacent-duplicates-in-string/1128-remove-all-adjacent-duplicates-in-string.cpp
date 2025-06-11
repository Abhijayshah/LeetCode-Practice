class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;

        for (char c : s) {
            if (!st.empty() && st.top() == c) {
                st.pop(); // Remove the duplicate
            } else {
                st.push(c); // Add character to the stack
            }
        }

        // Reconstruct the result from the stack
        string result;
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }

        reverse(result.begin(), result.end());
        return result;
    }
};
