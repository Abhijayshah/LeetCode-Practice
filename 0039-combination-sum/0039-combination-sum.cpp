class Solution {
public:
    vector<vector<int>> result;

    void backtrack(vector<int>& candidates, int index, int target, vector<int>& path) {
        if (target == 0) {
            result.push_back(path);
            return;
        }
        if (index == candidates.size() || target < 0)
            return;

        // Pick the current number
        if (candidates[index] <= target) {
            path.push_back(candidates[index]);
            backtrack(candidates, index, target - candidates[index], path);
            path.pop_back(); // backtrack
        }

        // Skip the current number
        backtrack(candidates, index + 1, target, path);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> path;
        backtrack(candidates, 0, target, path);
        return result;
    }
};
