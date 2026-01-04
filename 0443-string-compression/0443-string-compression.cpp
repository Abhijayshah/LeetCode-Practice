class Solution {
public:
    int compress(vector<char>& chars) {

        int n = chars.size();        // Original length
        int write = 0;               // Write pointer

        for (int read = 0; read < n; ) {

            char currentChar = chars[read]; // Current character
            int count = 0;

            // Count occurrences of current character
            while (read < n && chars[read] == currentChar) {
                read++;
                count++;
            }

            // Write the character
            chars[write] = currentChar;
            write++;

            // If count > 1, write its digits
            if (count > 1) {
                string cnt = to_string(count);   // Convert count to string
                for (char c : cnt) {
                    chars[write] = c;            // Write each digit
                    write++;
                }
            }
        }

        return write;                 // New compressed length
    }
};
