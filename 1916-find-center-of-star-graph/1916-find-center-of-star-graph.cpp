class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        // Check the first two edges
        // The common element in both edges is the center
        if (edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1]) {
            return edges[0][0];
        } else {
            return edges[0][1];
        }
    }
};
