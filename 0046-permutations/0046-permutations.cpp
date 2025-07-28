class Solution {
public:
    vector<vector<int>> result;

    void backtrack(vector<int>& nums, vector<int>& temp, vector<bool>& used) {
        if (temp.size() == nums.size()) {
            result.push_back(temp); // Found a permutation
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) continue; // Skip already used elements

            temp.push_back(nums[i]);
            used[i] = true;

            backtrack(nums, temp, used); // Recurse

            // Backtrack step
            temp.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> temp;
        vector<bool> used(nums.size(), false);
        backtrack(nums, temp, used);
        return result;
    }
};
