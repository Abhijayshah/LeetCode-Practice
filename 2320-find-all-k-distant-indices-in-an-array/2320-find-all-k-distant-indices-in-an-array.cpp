class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> result;
        int n = nums.size();

        // Find all positions where nums[j] == key
        vector<int> keyIndices;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == key) {
                keyIndices.push_back(i);
            }
        }

        // For each index in the array, check if it's within k distance of any key index
        for (int i = 0; i < n; ++i) {
            for (int j : keyIndices) {
                if (abs(i - j) <= k) {
                    result.push_back(i);
                    break; // only need one valid key position to include this index
                }
            }
        }

        return result;
    }
};
