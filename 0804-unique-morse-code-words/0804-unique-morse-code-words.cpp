class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> morse = {
            ".-","-...","-.-.","-..",".","..-.","--.","....","..",
            ".---","-.-",".-..","--","-.","---",".--.","--.-",".-.",
            "...","-","..-","...-",".--","-..-","-.--","--.."
        };
        
        unordered_set<string> st;
        
        for (string &word : words) {
            string transform = "";
            for (char c : word) {
                transform += morse[c - 'a'];
            }
            st.insert(transform);
        }
        
        return st.size();
    }
};
