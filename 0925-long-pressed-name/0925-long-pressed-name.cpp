class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i = 0; // Pointer for name string
        int j = 0; // Pointer for typed string
        
        while (j < typed.length()) { // Traverse typed completely
            
            if (i < name.length() && name[i] == typed[j]) {
                // If characters match, move both pointers
                i++;
                j++;
            }
            else if (j > 0 && typed[j] == typed[j - 1]) {
                // If current typed char matches previous typed char,
                // it is a long press → move typed pointer only
                j++;
            }
            else {
                // If characters do not match and not a valid long press
                return false;
            }
        }
        
        // After processing typed, all characters of name must be matched
        return i == name.length();
    }
};
