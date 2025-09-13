class Solution {
public:
    vector<int> transformArray(vector<int>& nums) {
        // Step 1 & 2: Replace even numbers with 0 and odd numbers with 1
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 == 0) {
                nums[i] = 0;  // Even number
            } else {
                nums[i] = 1;  // Odd number
            }
        }
        
        // Step 3: Sort the array in non-decreasing order
        sort(nums.begin(), nums.end());
        
        return nums;
    }
};