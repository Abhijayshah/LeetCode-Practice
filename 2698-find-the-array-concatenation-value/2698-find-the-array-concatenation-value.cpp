class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        int i = 0, j = nums.size() - 1;
        long long ans = 0;
        
        while (i < j) {
            int a = nums[i], b = nums[j];
            // Find number of digits in b
            int d = (b == 0) ? 1 : (int)log10(b) + 1;
            long long concat = (long long)a * pow(10, d) + b;
            ans += concat;
            i++;
            j--;
        }
        
        // If one element remains (odd length array)
        if (i == j) ans += nums[i];
        
        return ans;
    }
};
