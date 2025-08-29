class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size();
        int count = 0; // number of modifications needed
        
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                count++;
                if (count > 1) return false; // more than one modification needed
                
                // Decide which element to adjust
                if (i == 0 || nums[i - 1] <= nums[i + 1]) {
                    nums[i] = nums[i + 1];  // modify nums[i]
                } else {
                    nums[i + 1] = nums[i];  // modify nums[i+1]
                }
            }
        }
        
        return true;
    }
};
