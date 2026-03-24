class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        
        int n = s.length();
        
        string result(n, ' ');  
        // Create empty string of same size
        
        // Place each character at its correct index
        for(int i = 0; i < n; i++){
            result[indices[i]] = s[i];
        }
        
        return result;
    }
};