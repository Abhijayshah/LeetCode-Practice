class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int maxLen = 0;
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            if (nums[i] != -1) { // not visited
                int start = i;
                int count = 0;
                while (nums[start] != -1) {
                    int temp = nums[start];
                    nums[start] = -1; // mark as visited
                    start = temp;
                    count++;
                }
                maxLen = max(maxLen, count);
            }
        }

        return maxLen;
    }
};
