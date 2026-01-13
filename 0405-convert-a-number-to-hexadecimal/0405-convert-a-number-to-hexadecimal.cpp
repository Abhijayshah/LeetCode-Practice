class Solution {
public:
    string toHex(int num) {

        // Special case
        if (num == 0)
            return "0";

        string hex = "0123456789abcdef";
        string result = "";

        // Process up to 8 hex digits (32 bits)
        while (num != 0 && result.length() < 8) {

            int digit = num & 15;          // extract last 4 bits
            result = hex[digit] + result; // prepend hex digit

            num >>= 4;                     // arithmetic right shift
        }

        return result;
    }
};


