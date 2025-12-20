class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        // Map to store frequency of each element
        unordered_map<int, int> freq;
        
        // Maps to store first and last occurrence of each element
        unordered_map<int, int> firstOccurrence;
        unordered_map<int, int> lastOccurrence;
        
        // Populate the maps
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            
            // Increment frequency
            freq[num]++;
            
            // Store first occurrence (only if not seen before)
            if (firstOccurrence.find(num) == firstOccurrence.end()) {
                firstOccurrence[num] = i;
            }
            
            // Update last occurrence (always update)
            lastOccurrence[num] = i;
        }
        
        // Find the degree (maximum frequency)
        int degree = 0;
        for (auto& p : freq) {
            degree = max(degree, p.second);
        }
        
        // Find the shortest subarray with the same degree
        int minLength = nums.size();
        for (auto& p : freq) {
            int num = p.first;
            int count = p.second;
            
            // Only consider elements with frequency equal to degree
            if (count == degree) {
                int length = lastOccurrence[num] - firstOccurrence[num] + 1;
                minLength = min(minLength, length);
            }
        }
        
        return minLength;
    }
};

/*
Time Complexity: O(n)
- One pass to build the maps: O(n)
- Iterate through frequency map: O(unique elements) ≤ O(n)
- Overall: O(n)

Space Complexity: O(n)
- Three hash maps, each storing at most n unique elements

Example Walkthrough:

Example 1: nums = [1,2,2,3,1]
Step 1: Build maps
  freq: {1: 2, 2: 2, 3: 1}
  firstOccurrence: {1: 0, 2: 1, 3: 3}
  lastOccurrence: {1: 4, 2: 2, 3: 3}

Step 2: Find degree = 2 (max frequency)

Step 3: Find shortest subarray
  Element 1: frequency = 2, length = 4 - 0 + 1 = 5
  Element 2: frequency = 2, length = 2 - 1 + 1 = 2
  minLength = 2

Example 2: nums = [1,2,2,3,1,4,2]
Step 1: Build maps
  freq: {1: 2, 2: 3, 3: 1, 4: 1}
  firstOccurrence: {1: 0, 2: 1, 3: 3, 4: 5}
  lastOccurrence: {1: 4, 2: 6, 3: 3, 4: 5}

Step 2: Find degree = 3 (element 2 appears 3 times)

Step 3: Find shortest subarray
  Element 2: frequency = 3, length = 6 - 1 + 1 = 6
  minLength = 6
*/