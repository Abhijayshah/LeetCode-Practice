class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};
        
        // Sort intervals by start time
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> merged;
        merged.push_back(intervals[0]);
        
        for (int i = 1; i < intervals.size(); i++) {
            // Get the last interval in merged
            vector<int>& last = merged.back();
            vector<int>& current = intervals[i];
            
            // Check if current interval overlaps with last
            if (current[0] <= last[1]) {
                // Merge: extend the end time
                last[1] = max(last[1], current[1]);
            } else {
                // No overlap: add as new interval
                merged.push_back(current);
            }
        }
        
        return merged;
    }
};