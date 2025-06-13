#include <vector>

class Solution {
public:
    int findJudge(int n, std::vector<std::vector<int>>& trust) {
        // Initialize trust counts
        std::vector<int> trustCount(n + 1, 0);
        
        // Process each trust relationship
        for (const auto& relation : trust) {
            int a = relation[0]; // person who trusts
            int b = relation[1]; // person who is trusted
            
            trustCount[a]--; // a trusts someone, so decrease their count
            trustCount[b]++; // b is trusted by someone, so increase their count
        }
        
        // Find the town judge
        for (int i = 1; i <= n; ++i) {
            if (trustCount[i] == n - 1) {
                return i; // found the judge
            }
        }
        
        return -1; // no judge found
    }
};
