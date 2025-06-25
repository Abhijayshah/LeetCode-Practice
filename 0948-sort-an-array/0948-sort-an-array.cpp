class Solution {
public:
    void heapify(vector<int>& nums, int n, int i) {
        int largest = i;         // Initialize largest as root
        int left = 2 * i + 1;    // left child
        int right = 2 * i + 2;   // right child

        if (left < n && nums[left] > nums[largest])
            largest = left;

        if (right < n && nums[right] > nums[largest])
            largest = right;

        if (largest != i) {
            swap(nums[i], nums[largest]);
            heapify(nums, n, largest); // Recursively heapify the affected subtree
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();

        // Build max heap
        for (int i = n / 2 - 1; i >= 0; i--)
            heapify(nums, n, i);

        // Extract elements from heap one by one
        for (int i = n - 1; i > 0; i--) {
            swap(nums[0], nums[i]); // Move current root to end
            heapify(nums, i, 0);    // Heapify reduced heap
        }

        return nums;
    }
};
