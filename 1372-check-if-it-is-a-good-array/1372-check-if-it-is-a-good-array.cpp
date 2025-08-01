class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        int g = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            g = __gcd(g, nums[i]);
            if (g == 1) return true;  // early exit
        }
        return g == 1;
    }
};
