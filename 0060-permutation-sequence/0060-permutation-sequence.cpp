class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> factorial(n);
        vector<int> numbers;
        
        // Calculate factorials and initialize numbers array
        factorial[0] = 1;
        for (int i = 1; i < n; i++) {
            factorial[i] = factorial[i-1] * i;
        }
        
        for (int i = 1; i <= n; i++) {
            numbers.push_back(i);
        }
        
        string result = "";
        k--; // Convert to 0-based indexing
        
        for (int i = n; i >= 1; i--) {
            int index = k / factorial[i-1];
            result += to_string(numbers[index]);
            numbers.erase(numbers.begin() + index);
            k %= factorial[i-1];
        }
        
        return result;
    }
};