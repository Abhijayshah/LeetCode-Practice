class Solution {
public:
    long long minEnd(int n, int x) {
        // We need to construct n numbers where their AND is x
        // Each number must have all bits of x set (to preserve x in AND)
        // We can only modify bits where x has 0
        
        long long result = x;
        long long remaining = n - 1; // We need n-1 more numbers after x
        
        // Find positions where x has 0 bits - these are positions we can modify
        long long position = 1;
        
        while (remaining > 0) {
            // Find the next position where x has a 0 bit
            while ((x & position) != 0) {
                position <<= 1;
            }
            
            // If remaining has this bit set, set it in result
            if (remaining & 1) {
                result |= position;
            }
            
            remaining >>= 1;
            position <<= 1;
        }
        
        return result;
    }
};