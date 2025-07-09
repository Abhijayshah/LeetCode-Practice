#include <vector>
#include <cmath> // For abs function

class Solution {
public:
    int findClosestNumber(std::vector<int>& nums) {
        int closest = nums[0]; // Initialize closest to the first element

        for (int num : nums) {
            // Check if the current number is closer to zero
            if (abs(num) < abs(closest) || (abs(num) == abs(closest) && num > closest)) {
                closest = num; // Update closest number
            }
        }

        return closest; // Return the closest number to zero
    }
};
