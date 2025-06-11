class Solution {
public:
    string reverseVowels(string s) {
        // Define a set of vowels for quick lookup
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 
                                       'A', 'E', 'I', 'O', 'U'};
        
        int left = 0; // Pointer starting from the beginning
        int right = s.length() - 1; // Pointer starting from the end
        
        // Convert the string to a vector of characters for easy manipulation
        vector<char> charArray(s.begin(), s.end());
        
        while (left < right) {
            // Move the left pointer to the next vowel
            while (left < right && vowels.find(charArray[left]) == vowels.end()) {
                left++;
            }
            // Move the right pointer to the previous vowel
            while (left < right && vowels.find(charArray[right]) == vowels.end()) {
                right--;
            }
            // Swap the vowels
            if (left < right) {
                swap(charArray[left], charArray[right]);
                left++;
                right--;
            }
        }
        
        // Convert the character array back to a string
        return string(charArray.begin(), charArray.end());
    }
};
