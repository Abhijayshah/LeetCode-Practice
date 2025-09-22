class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        unordered_map<int, int> freq;
        
        // Count frequencies
        for (int num : nums) {
            freq[num]++;
            // If any element appears more than 2 times, not possible
            if (freq[num] > 2) return false;
        }
        
        return true;
    }
};
