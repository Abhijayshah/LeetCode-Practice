class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return false;  // At least 3 parts needed

        int i = 0;

        // Step 1: Increasing part
        while (i + 1 < n && nums[i] < nums[i + 1]) i++;
        int p = i;

        // Step 2: Decreasing part
        while (i + 1 < n && nums[i] > nums[i + 1]) i++;
        int q = i;

        // Step 3: Increasing part
        while (i + 1 < n && nums[i] < nums[i + 1]) i++;

        // Valid if:
        // - we reached the end
        // - p and q are valid indices
        return (i == n - 1 && p > 0 && q > p && q < n - 1);
    }
};
