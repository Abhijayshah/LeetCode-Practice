class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() || s[0] == '0') {
            return 0;
        }
        
        int n = s.length();
        vector<int> dp(n + 1, 0);
        
        // Base cases
        dp[0] = 1; // Empty string has one way to decode
        dp[1] = 1; // First character (already checked it's not '0')
        
        for (int i = 2; i <= n; i++) {
            // Check single digit (current character)
            if (s[i-1] != '0') {
                dp[i] += dp[i-1];
            }
            
            // Check two digits (previous + current character)
            int twoDigit = (s[i-2] - '0') * 10 + (s[i-1] - '0');
            if (twoDigit >= 10 && twoDigit <= 26) {
                dp[i] += dp[i-2];
            }
        }
        
        return dp[n];
    }
};

// Space-optimized version (O(1) space)
class SolutionOptimized {
public:
    int numDecodings(string s) {
        if (s.empty() || s[0] == '0') {
            return 0;
        }
        
        int n = s.length();
        int prev2 = 1; // dp[i-2]
        int prev1 = 1; // dp[i-1]
        
        for (int i = 2; i <= n; i++) {
            int current = 0;
            
            // Check single digit
            if (s[i-1] != '0') {
                current += prev1;
            }
            
            // Check two digits
            int twoDigit = (s[i-2] - '0') * 10 + (s[i-1] - '0');
            if (twoDigit >= 10 && twoDigit <= 26) {
                current += prev2;
            }
            
            // Update for next iteration
            prev2 = prev1;
            prev1 = current;
        }
        
        return prev1;
    }
};

// Recursive solution with memoization (for understanding)
class SolutionRecursive {
private:
    unordered_map<int, int> memo;
    
    int helper(const string& s, int index) {
        if (index == s.length()) {
            return 1; // Successfully decoded entire string
        }
        
        if (s[index] == '0') {
            return 0; // Invalid - leading zero
        }
        
        if (memo.find(index) != memo.end()) {
            return memo[index];
        }
        
        int result = 0;
        
        // Try single digit (1-9)
        result += helper(s, index + 1);
        
        // Try two digits (10-26)
        if (index + 1 < s.length()) {
            int twoDigit = (s[index] - '0') * 10 + (s[index + 1] - '0');
            if (twoDigit >= 10 && twoDigit <= 26) {
                result += helper(s, index + 2);
            }
        }
        
        memo[index] = result;
        return result;
    }
    
public:
    int numDecodings(string s) {
        memo.clear();
        return helper(s, 0);
    }
};

// Test function to demonstrate all approaches
void testSolution() {
    Solution solution;
    SolutionOptimized solutionOpt;
    SolutionRecursive solutionRec;
    
    vector<string> testCases = {
        "12",     // Expected: 2
        "226",    // Expected: 3
        "06",     // Expected: 0
        "10",     // Expected: 1
        "2101",   // Expected: 1
        "11106",  // Expected: 2
        "111111", // Expected: 13
        "0",      // Expected: 0
        "1"       // Expected: 1
    };
    
    cout << "Testing Decode Ways Solutions:\n\n";
    
    for (const string& test : testCases) {
        int result1 = solution.numDecodings(test);
        int result2 = solutionOpt.numDecodings(test);
        int result3 = solutionRec.numDecodings(test);
        
        cout << "Input: \"" << test << "\"\n";
        cout << "DP Solution: " << result1 << "\n";
        cout << "Optimized: " << result2 << "\n";
        cout << "Recursive: " << result3 << "\n";
        
        // Verify all solutions match
        if (result1 == result2 && result2 == result3) {
            cout << "✓ All solutions match\n\n";
        } else {
            cout << "✗ Solutions don't match!\n\n";
        }
    }
}

// Detailed explanation of the algorithm
void explainAlgorithm() {
    cout << "DECODE WAYS ALGORITHM EXPLANATION:\n\n";
    
    cout << "Problem: Count ways to decode a numeric string to letters (1-26 -> A-Z)\n\n";
    
    cout << "Key Insights:\n";
    cout << "1. At each position, we can either:\n";
    cout << "   - Use current digit alone (if it's 1-9)\n";
    cout << "   - Use current + previous digit together (if it's 10-26)\n\n";
    
    cout << "2. Dynamic Programming Recurrence:\n";
    cout << "   dp[i] = ways to decode string up to position i\n";
    cout << "   dp[i] = dp[i-1] (if single digit valid) + dp[i-2] (if two digits valid)\n\n";
    
    cout << "3. Base Cases:\n";
    cout << "   dp[0] = 1 (empty string)\n";
    cout << "   dp[1] = 1 (if first character is not '0')\n\n";
    
    cout << "4. Invalid Cases:\n";
    cout << "   - Leading zeros (like '06')\n";
    cout << "   - Numbers > 26 for two-digit combinations\n\n";
    
    cout << "Example Walkthrough for '226':\n";
    cout << "Position 0: '' -> 1 way\n";
    cout << "Position 1: '2' -> 1 way (B)\n";
    cout << "Position 2: '22' -> 2 ways (BB or V)\n";
    cout << "Position 3: '226' -> 3 ways (BBF, VF, BZ)\n\n";
    
    cout << "Time Complexity: O(n)\n";
    cout << "Space Complexity: O(n) for DP array, O(1) for optimized version\n";
}