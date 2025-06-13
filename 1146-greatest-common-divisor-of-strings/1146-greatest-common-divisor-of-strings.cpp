#include <string>
#include <numeric> // for std::gcd

class Solution {
public:
    std::string gcdOfStrings(std::string str1, std::string str2) {
        // Check if str1 + str2 is equal to str2 + str1
        if (str1 + str2 != str2 + str1) {
            return "";
        }
        
        // Find the GCD of the lengths of str1 and str2
        int gcdLength = std::gcd(str1.length(), str2.length());
        
        // Return the substring of str1 up to gcdLength
        return str1.substr(0, gcdLength);
    }
};
