class Solution {
public:
    string thousandSeparator(int n) {
        string num = to_string(n);
        string res = "";
        int count = 0;

        // Traverse from right
        for (int i = num.size() - 1; i >= 0; i--) {
            res += num[i];
            count++;

            // Add dot after every 3 digits (except last group)
            if (count == 3 && i != 0) {
                res += '.';
                count = 0;
            }
        }

        // Reverse to get correct order
        reverse(res.begin(), res.end());
        return res;
    }
};