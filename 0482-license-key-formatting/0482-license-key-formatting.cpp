class Solution {
public:
    string licenseKeyFormatting(string s, int k) {

        string result = "";
        int count = 0;

        // Traverse from right to left
        for (int i = s.length() - 1; i >= 0; i--) {

            if (s[i] == '-') continue;

            // Add dash after k characters
            if (count == k) {
                result.push_back('-');
                count = 0;
            }

            // Add uppercase character
            result.push_back(toupper(s[i]));
            count++;
        }

        // Reverse to correct order
        reverse(result.begin(), result.end());

        return result;
    }
};
