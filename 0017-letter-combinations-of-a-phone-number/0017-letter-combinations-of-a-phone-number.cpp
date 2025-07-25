class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        // Mapping digits to letters
        vector<string> mapping = {
            "",     "",     "abc", "def", "ghi", 
            "jkl",  "mno",  "pqrs", "tuv", "wxyz"
        };

        vector<string> result;
        string current;
        backtrack(digits, 0, current, result, mapping);
        return result;
    }

    void backtrack(const string& digits, int index, string& current, vector<string>& result, const vector<string>& mapping) {
        if (index == digits.length()) {
            result.push_back(current);
            return;
        }

        string letters = mapping[digits[index] - '0'];
        for (char ch : letters) {
            current.push_back(ch);
            backtrack(digits, index + 1, current, result, mapping);
            current.pop_back(); // backtrack
        }
    }
};
