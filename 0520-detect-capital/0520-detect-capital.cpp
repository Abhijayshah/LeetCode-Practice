class Solution {
public:
    bool detectCapitalUse(string word) {

        int caps = 0;
        int n = word.size();

        // Count uppercase letters
        for (char c : word) {
            if (isupper(c))
                caps++;
        }

        // Case 1: All uppercase
        if (caps == n)
            return true;

        // Case 2: All lowercase
        if (caps == 0)
            return true;

        // Case 3: Only first letter uppercase
        if (caps == 1 && isupper(word[0]))
            return true;

        return false;
    }
};
