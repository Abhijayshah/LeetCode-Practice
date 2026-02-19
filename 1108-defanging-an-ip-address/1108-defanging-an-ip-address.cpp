class Solution {
public:
    string defangIPaddr(string address) {
        
        string result = ""; // Store modified IP address
        
        // Traverse each character in the address
        for (char ch : address) {
            
            if (ch == '.') {
                // Replace '.' with "[.]"
                result += "[.]";
            }
            else {
                // Otherwise append the character as it is
                result += ch;
            }
        }
        
        return result; // Return defanged IP address
    }
};
