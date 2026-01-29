class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int lines = 1; // Start with 1 line (at least one line needed)
        int currentWidth = 0; // Track current line width in pixels
        
        for (char c : s) { // Iterate through each character in string
            int charWidth = widths[c - 'a']; // Get width of current character (c-'a' gives index 0-25)
            
            if (currentWidth + charWidth > 100) { // If adding this char exceeds 100 pixels
                lines++; // Start a new line
                currentWidth = charWidth; // Reset width to current character's width
            } else { // Character fits on current line
                currentWidth += charWidth; // Add character width to current line
            }
        }
        
        return {lines, currentWidth}; // Return [total lines, last line width]
    }
};