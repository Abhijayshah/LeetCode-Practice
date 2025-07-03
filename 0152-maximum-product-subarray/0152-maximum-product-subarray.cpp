class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) return 0;

        int maxProd = nums[0];
        int minProd = nums[0];
        int ans = nums[0];

        for (int i = 1; i < nums.size(); ++i) {
            // Save current max before updating it
            int tempMax = maxProd;

            maxProd = max({nums[i], nums[i] * maxProd, nums[i] * minProd});
            minProd = min({nums[i], nums[i] * tempMax, nums[i] * minProd});

            ans = max(ans, maxProd);
        }

        return ans;
    }
};
