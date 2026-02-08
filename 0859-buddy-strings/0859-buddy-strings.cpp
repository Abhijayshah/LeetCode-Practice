class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if (s.length() != goal.length()) { // If lengths differ, impossible to match
            return false;
        }
        
        if (s == goal) { // If strings are already equal
            unordered_set<char> seen; // Set to track duplicate characters
            for (char c : s) { // Loop through each character
                if (seen.count(c)) { // If character already exists
                    return true; // We can swap duplicate chars
                }
                seen.insert(c); // Add character to set
            }
            return false; // No duplicates found, can't swap without changing
        }
        
        vector<int> diff; // Store indices where s and goal differ
        
        for (int i = 0; i < s.length(); i++) { // Compare each position
            if (s[i] != goal[i]) { // If characters differ
                diff.push_back(i); // Store the differing index
            }
        }
        
        if (diff.size() != 2) { // Must have exactly 2 differences for valid swap
            return false;
        }
        
        // Check if swapping the two differing positions makes strings equal
        return (s[diff[0]] == goal[diff[1]] && s[diff[1]] == goal[diff[0]]);
    }
};