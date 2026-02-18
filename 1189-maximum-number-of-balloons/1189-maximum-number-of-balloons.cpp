class Solution {
public:
    int maxNumberOfBalloons(string text) {
        
        // Frequency array for all lowercase letters
        vector<int> freq(26, 0);
        
        // Count frequency of each character in text
        for (char ch : text) {
            freq[ch - 'a']++; // Increment count
        }
        
        // Calculate how many times "balloon" can be formed
        // Note: 'l' and 'o' are required twice
        
        int count_b = freq['b' - 'a'];        // Number of 'b'
        int count_a = freq['a' - 'a'];        // Number of 'a'
        int count_l = freq['l' - 'a'] / 2;    // 'l' appears twice
        int count_o = freq['o' - 'a'] / 2;    // 'o' appears twice
        int count_n = freq['n' - 'a'];        // Number of 'n'
        
        // The answer is the minimum of all required counts
        return min({count_b, count_a, count_l, count_o, count_n});
    }
};
