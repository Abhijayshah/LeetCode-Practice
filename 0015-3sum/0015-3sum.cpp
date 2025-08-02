class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // Sort the array to enable two-pointer technique.
        vector<vector<int>> result;
        
        for (int i = 0; i < nums.size() && nums[i] <= 0; ++i) // Only consider nums[i] ≤ 0 to avoid redundancy.
            if (i == 0 || nums[i - 1] != nums[i]) { // Check to skip over duplicate values.
                twoSumII(nums, i, result);
            }
        
        return result;
    }
    
private:
    void twoSumII(const vector<int>& nums, int i, vector<vector<int>>& res) {
        int left = i + 1, right = nums.size() - 1;
        
        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            if (sum < 0) {
                ++left;
            } else if (sum > 0) {
                --right;
            } else {
                res.push_back({ nums[i], nums[left], nums[right] });
                left++;
                right--;
                while (left < right && nums[left] == nums[left - 1]) // Skip duplicates
                    ++left;
            }
        }
    }
};
