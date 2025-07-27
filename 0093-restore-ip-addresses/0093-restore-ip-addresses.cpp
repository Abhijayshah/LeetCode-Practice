class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        // A valid IP string must be between 4 and 12 characters long.
        if (s.length() < 4 || s.length() > 12) {
            return result;
        }
        
        vector<string> current_path;
        backtrack(s, 0, current_path, result);
        return result;
    }

private:
    /**
     * @brief Recursively finds valid IP address partitions.
     * @param s The original input string.
     * @param index The starting index in 's' for the next part.
     * @param path A vector storing the parts of the IP address found so far.
     * @param result A vector to store the final valid IP address strings.
     */
    void backtrack(const string& s, int index, vector<string>& path, vector<string>& result) {
        // Base case: If we have 4 parts and have consumed the entire string.
        if (path.size() == 4) {
            if (index == s.length()) {
                // Join the parts with dots to form the final IP address.
                result.push_back(path[0] + "." + path[1] + "." + path[2] + "." + path[3]);
            }
            return;
        }

        // Try to form the next part using 1, 2, or 3 digits.
        for (int len = 1; len <= 3 && index + len <= s.length(); ++len) {
            string part = s.substr(index, len);

            // Constraint 1: No leading zeros unless the part is just "0".
            if (part.length() > 1 && part[0] == '0') {
                continue;
            }
            
            // Constraint 2: The integer value must be <= 255.
            if (stoi(part) > 255) {
                continue;
            }

            // If the part is valid, choose it and recurse.
            path.push_back(part);
            backtrack(s, index + len, path, result);
            
            // Backtrack by removing the part to explore other possibilities.
            path.pop_back();
        }
    }
};