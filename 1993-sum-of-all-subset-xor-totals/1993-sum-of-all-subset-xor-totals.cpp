class Solution {
public:
    int total_sum_of_xors = 0; // Member variable to store the overall sum

    void backtrack(const std::vector<int>& nums, int index, int current_xor_sum) {
        // Base case: If we've considered all elements, add the current_xor_sum to the total
        if (index == nums.size()) {
            total_sum_of_xors += current_xor_sum;
            return;
        }

        // Recursive step 1: Include the current element (nums[index])
        // XOR it with the current_xor_sum and move to the next element
        backtrack(nums, index + 1, current_xor_sum ^ nums[index]);

        // Recursive step 2: Exclude the current element (nums[index])
        // Keep current_xor_sum as is and move to the next element
        backtrack(nums, index + 1, current_xor_sum);
    }

    int subsetXORSum(std::vector<int>& nums) {
        // Start the backtracking process from the first element with an initial XOR sum of 0
        backtrack(nums, 0, 0);
        return total_sum_of_xors;
    }
};