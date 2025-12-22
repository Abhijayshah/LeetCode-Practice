class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int leftMax = nums[0];
        int globalMax = nums[0];
        int partitionIndex = 0;

        for (int i = 1; i < nums.size(); i++) {
            globalMax = max(globalMax, nums[i]);

            if (nums[i] < leftMax) {
                partitionIndex = i;
                leftMax = globalMax;
            }
        }

        return partitionIndex + 1;
    }
};
