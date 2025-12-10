class Solution {
public:
    int reverseBits(int n) {

        unsigned int res = 0;

        for(int i = 0; i < 32; i++){
            int bit = (n & 1);     // extract last bit
            res = (res << 1) | bit; // append bit to result
            n >>= 1;               // move to next bit
        }

        return res;
    }
};
