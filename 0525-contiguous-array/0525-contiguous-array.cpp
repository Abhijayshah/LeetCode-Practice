class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> map; // prefix sum to index
        map[0] = -1; // base case for sum = 0 at index -1

        int maxLen = 0;
        int count = 0;

        for (int i = 0; i < nums.size(); ++i) {
            // Treat 0 as -1, 1 as +1
            count += (nums[i] == 1) ? 1 : -1;

            if (map.find(count) != map.end()) {
                maxLen = max(maxLen, i - map[count]);
            } else {
                map[count] = i;
            }
        }

        return maxLen;
    }
};
