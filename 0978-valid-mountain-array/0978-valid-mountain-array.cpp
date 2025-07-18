class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n = arr.size();
        
        // Check if the array has at least 3 elements
        if (n < 3) return false;

        int i = 0;

        // Climb up the mountain
        while (i + 1 < n && arr[i] < arr[i + 1]) {
            i++;
        }

        // Peak can't be the first or last element
        if (i == 0 || i == n - 1) return false;

        // Climb down the mountain
        while (i + 1 < n && arr[i] > arr[i + 1]) {
            i++;
        }

        // If we reached the end, it's a valid mountain array
        return i == n - 1;
    }
};
