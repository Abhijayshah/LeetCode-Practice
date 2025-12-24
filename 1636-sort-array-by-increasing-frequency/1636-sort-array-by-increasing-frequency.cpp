class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {

        // Step 1: Count frequency of each number
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        // Step 2: Sort nums using custom comparator
        sort(nums.begin(), nums.end(), [&](int a, int b) {

            // If frequency is different, smaller frequency comes first
            if (freq[a] != freq[b])
                return freq[a] < freq[b];

            // If frequency is same, larger value comes first
            return a > b;
        });

        return nums;
    }
};
