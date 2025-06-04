class Solution {
public:
    int subarrayLCM(vector<int>& nums, int k) {
        int count = 0;
        int n = nums.size();
        
        for (int i = 0; i < n; ++i) {
            long long lcm = nums[i];
            if (lcm == k) count++;
            for (int j = i + 1; j < n; ++j) {
                lcm = lcm * nums[j] / gcd(lcm, nums[j]);
                if (lcm > k) break;
                if (lcm == k) count++;
            }
        }
        
        return count;
    }

private:
    // Euclidean algorithm for GCD
    long long gcd(long long a, long long b) {
        return b == 0 ? a : gcd(b, a % b);
    }
};
