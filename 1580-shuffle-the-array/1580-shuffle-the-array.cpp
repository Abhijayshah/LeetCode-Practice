class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> result;
        
        // Interleave elements from first half and second half
        for (int i = 0; i < n; i++) {
            result.push_back(nums[i]);     // x element from first half
            result.push_back(nums[i + n]); // y element from second half
        }
        
        return result;
    }
};