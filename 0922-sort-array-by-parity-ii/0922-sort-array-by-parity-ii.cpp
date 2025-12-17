class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {

        vector<int> even;                 // Store even numbers
        vector<int> odd;                  // Store odd numbers

        // Separate even and odd numbers
        for (int num : nums) {
            if (num % 2 == 0)
                even.push_back(num);
            else
                odd.push_back(num);
        }

        vector<int> result(nums.size());  // Result array

        int e = 0, o = 0;                  // Index for even and odd arrays

        for (int i = 0; i < nums.size(); i++) {
            if (i % 2 == 0) {              // Even index
                result[i] = even[e++];
            } else {                       // Odd index
                result[i] = odd[o++];
            }
        }

        return result;                     // Return rearranged array
    }
};
