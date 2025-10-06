class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> result;
        int num = 0;

        for (int b : nums) {
            num = ((num << 1) + b) % 5; // multiply by 2 and add current bit, then take mod 5
            result.push_back(num == 0);
        }

        return result;
    }
};
