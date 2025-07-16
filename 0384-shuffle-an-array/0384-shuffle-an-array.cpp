class Solution {
private:
    vector<int> original;
    vector<int> current;

public:
    // Constructor: store original and current array
    Solution(vector<int>& nums) {
        original = nums;
        current = nums;
    }

    // Reset to original
    vector<int> reset() {
        current = original;
        return current;
    }

    // Fisher–Yates Shuffle
    vector<int> shuffle() {
        int n = current.size();
        for (int i = n - 1; i > 0; --i) {
            int j = rand() % (i + 1); // random index from 0 to i
            swap(current[i], current[j]);
        }
        return current;
    }
};
