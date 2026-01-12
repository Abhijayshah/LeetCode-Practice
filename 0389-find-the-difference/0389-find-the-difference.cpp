class Solution {
public:
    char findTheDifference(string s, string t) {

        char result = 0;

        // XOR all characters of s
        for (char c : s) {
            result ^= c;
        }

        // XOR all characters of t
        for (char c : t) {
            result ^= c;
        }

        // Remaining character is the added one
        return result;
    }
};
