class Solution {
public:
    int findClosest(int x, int y, int z) {
        // Calculate the distances
        int distance1 = abs(x - z); // Distance from Person 1 to Person 3
        int distance2 = abs(y - z); // Distance from Person 2 to Person 3
        
        // Compare distances and return the result
        if (distance1 < distance2) {
            return 1; // Person 1 arrives first
        } else if (distance2 < distance1) {
            return 2; // Person 2 arrives first
        } else {
            return 0; // Both arrive at the same time
        }
    }
};
