class Solution {
public:
    int maxVowels(string s, int k) {
        int maxVowelCount = 0;
        int currentVowelCount = 0;
        int n = s.length();
        
        // Define a set of vowels for easy checking
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        
        // Count vowels in the first window of size k
        for (int i = 0; i < k; i++) {
            if (vowels.count(s[i])) {
                currentVowelCount++;
            }
        }
        
        maxVowelCount = currentVowelCount;
        
        // Slide the window across the string
        for (int i = k; i < n; i++) {
            // Remove the character going out of the window
            if (vowels.count(s[i - k])) {
                currentVowelCount--;
            }
            // Add the new character coming into the window
            if (vowels.count(s[i])) {
                currentVowelCount++;
            }
            // Update the maximum vowel count
            maxVowelCount = max(maxVowelCount, currentVowelCount);
        }
        
        return maxVowelCount;
    }
};
