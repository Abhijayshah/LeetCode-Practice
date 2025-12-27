class Solution {
public:
    bool isGood(vector<int>& nums) {

        int n = nums.size();                      // Length of array
        int mx = *max_element(nums.begin(), nums.end()); // Find max element

        // Condition 1: Length must be mx + 1
        if (n != mx + 1) {
            return false;
        }

        vector<int> freq(mx + 1, 0);              // Frequency array

        // Count frequencies
        for (int x : nums) {
            if (x > mx) return false;             // Safety check
            freq[x]++;
        }

        // Check numbers from 1 to mx-1 appear exactly once
        for (int i = 1; i < mx; i++) {
            if (freq[i] != 1) {
                return false;
            }
        }

        // Check mx appears exactly twice
        if (freq[mx] != 2) {
            return false;
        }

        return true;                              // All conditions satisfied
    }
};
