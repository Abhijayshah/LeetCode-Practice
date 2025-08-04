class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1.0;
        
        long long N = n;  // Use long long to handle INT_MIN overflow
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }
        
        double result = 1.0;
        double current_power = x;
        
        while (N > 0) {
            if (N % 2 == 1) {  // If N is odd
                result *= current_power;
            }
            current_power *= current_power;  // Square the base
            N /= 2;  // Divide exponent by 2
        }
        
        return result;
    }
};