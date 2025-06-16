class Solution {
public:
    int hammingDistance(int x, int y) {
        int xorVal = x ^ y;
        int count = 0;

        while (xorVal) {
            count += xorVal & 1;  // Add 1 if the last bit is set
            xorVal >>= 1;         // Right shift by 1 to check next bit
        }

        return count;
    }
};
