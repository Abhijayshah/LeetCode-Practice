class Solution {
public:
    
    // XOR of all numbers from 0 to x
    int xorTill(int x) {
        if (x % 4 == 0) return x;
        if (x % 4 == 1) return 1;
        if (x % 4 == 2) return x + 1;
        return 0;
    }

    int xorOperation(int n, int start) {

        int s = start >> 1;                          // start / 2
        int xorRange = xorTill(s - 1) ^ xorTill(s + n - 1);
        int result = xorRange << 1;                  // Multiply back by 2

        if (start % 2 == 1 && n % 2 == 1) {
            result |= 1;                             // Fix last bit if needed
        }

        return result;
    }
};
