class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;

    void backtrack(int start, int n, int k) {
        // If current combination has k numbers, add to result
        if (temp.size() == k) {
            ans.push_back(temp);
            return;
        }

        // Try picking numbers from start..n
        for (int i = start; i <= n; i++) {
            temp.push_back(i);         // choose i
            backtrack(i + 1, n, k);    // recurse with next number
            temp.pop_back();           // backtrack
        }
    }

    vector<vector<int>> combine(int n, int k) {
        backtrack(1, n, k);
        return ans;
    }
};
