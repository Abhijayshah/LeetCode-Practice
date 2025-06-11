class Solution {
public:
    bool rotateString(string s, string goal) {
        // Check if lengths are different, early return
        if (s.length() != goal.length()) return false;

        // Concatenate s with itself
        string doubleS = s + s;

        // If goal is a substring of doubleS, it is a rotation
        return doubleS.find(goal) != string::npos;
    }
};
