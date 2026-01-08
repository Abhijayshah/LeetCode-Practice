class Solution {
public:
    bool isAnagram(string s, string t) {

        if (s.length() != t.length())        // Lengths must be equal
            return false;

        sort(s.begin(), s.end());            // Sort first string
        sort(t.begin(), t.end());            // Sort second string

        return s == t;                        // Compare sorted strings
    }
};
