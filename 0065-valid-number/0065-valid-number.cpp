class Solution {
public:
    bool isNumber(string s) {
        // Trim leading/trailing spaces if needed (problem states no spaces, so omitted)

        // State machine approach
        int i = 0, n = s.size();

        // 1. Optional sign
        if (i < n && (s[i] == '+' || s[i] == '-')) ++i;

        bool isNumeric = false;
        // 2. Digits before decimal
        while (i < n && isdigit(s[i])) { ++i; isNumeric = true; }

        // 3. Decimal point
        if (i < n && s[i] == '.') {
            ++i;
            // Digits after decimal
            while (i < n && isdigit(s[i])) { ++i; isNumeric = true; }
        }

        // If no numeric part yet, not a number (e.g., just "." or "+.")
        if (!isNumeric) return false;

        // 4. Exponent
        if (i < n && (s[i] == 'e' || s[i] == 'E')) {
            ++i;
            // Exponent sign
            if (i < n && (s[i] == '+' || s[i] == '-')) ++i;

            bool expNumeric = false;
            while (i < n && isdigit(s[i])) { ++i; expNumeric = true; }
            if (!expNumeric) return false;
        }

        // All characters must be consumed
        return i == n;
    }
};