class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int slow = 0; // index to place the next non-zero
        for (int fast = 0; fast < nums.size(); ++fast) {
            if (nums[fast] != 0) {
                if (slow != fast) {
                    swap(nums[slow], nums[fast]); // only swap if needed
                }
                ++slow;
            }
        }
    }
};
