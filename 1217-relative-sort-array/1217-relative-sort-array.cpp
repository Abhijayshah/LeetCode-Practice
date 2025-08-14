class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        // Count frequency of each element in arr1
        unordered_map<int, int> count;
        for (int num : arr1) {
            count[num]++;
        }
        
        vector<int> result;
        
        // First, add elements in the order they appear in arr2
        for (int num : arr2) {
            // Add all occurrences of this number
            for (int i = 0; i < count[num]; i++) {
                result.push_back(num);
            }
            // Remove this element from count map
            count.erase(num);
        }
        
        // Collect remaining elements (not in arr2)
        vector<int> remaining;
        for (auto& pair : count) {
            for (int i = 0; i < pair.second; i++) {
                remaining.push_back(pair.first);
            }
        }
        
        // Sort remaining elements in ascending order
        sort(remaining.begin(), remaining.end());
        
        // Add remaining elements to result
        for (int num : remaining) {
            result.push_back(num);
        }
        
        return result;
    }
};