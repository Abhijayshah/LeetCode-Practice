class Solution {
public:
    string reformat(string s) {
        
        string letters = ""; // Store all letters
        string digits = "";  // Store all digits
        
        // Separate letters and digits
        for (char c : s) {
            
            if (isalpha(c))
                letters += c; // Append letter
            else
                digits += c;  // Append digit
        }
        
        // If difference > 1, cannot alternate properly
        if (abs((int)letters.size() - (int)digits.size()) > 1)
            return "";
        
        string result = ""; // Store final string
        
        // Decide which type starts first
        bool letterTurn = letters.size() > digits.size();
        
        int i = 0, j = 0; // Pointers for letters and digits
        
        // Build result alternately
        while (i < letters.size() || j < digits.size()) {
            
            if (letterTurn && i < letters.size()) {
                result += letters[i++]; // Add letter
            }
            else if (!letterTurn && j < digits.size()) {
                result += digits[j++]; // Add digit
            }
            
            letterTurn = !letterTurn; // Alternate type
        }
        
        return result; // Return reformatted string
    }
};