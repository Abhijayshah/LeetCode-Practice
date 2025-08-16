class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long miss = 1;  // The smallest number we cannot form yet
        int patches = 0;     // Number of patches added
        int i = 0;           // Index for nums array
        
        while (miss <= n) {
            // If current number in nums can help fill the gap
            if (i < nums.size() && nums[i] <= miss) {
                // We can now form all numbers from 1 to (miss + nums[i] - 1)
                miss += nums[i];
                i++;
            } else {
                // We need to patch 'miss' to fill the gap
                // After adding 'miss', we can form all numbers from 1 to (miss + miss - 1)
                miss += miss;  // Equivalent to miss *= 2
                patches++;
            }
        }
        
        return patches;
    }
};

// Alternative implementation with detailed comments
class Solution2 {
public:
    int minPatches(vector<int>& nums, int n) {
        long long maxReach = 0;  // Maximum sum we can form continuously from 1
        int patches = 0;
        int i = 0;
        
        while (maxReach < n) {
            // If we can use the current number from nums
            if (i < nums.size() && nums[i] <= maxReach + 1) {
                // Extend our reach by including this number
                maxReach += nums[i];
                i++;
            } else {
                // We have a gap at (maxReach + 1)
                // Patch it by adding (maxReach + 1)
                maxReach += (maxReach + 1);  // Same as maxReach = 2 * maxReach + 1
                patches++;
            }
        }
        
        return patches;
    }
};