class Solution {
public:
    string reverseOnlyLetters(string s) {
        int left = 0, right = s.size() - 1;

        while (left < right) {
            // Move left until it points to a letter
            while (left < right && !isalpha(s[left])) {
                left++;
            }

            // Move right until it points to a letter
            while (left < right && !isalpha(s[right])) {
                right--;
            }

            // Swap the letters
            swap(s[left], s[right]);
            left++;
            right--;
        }

        return s;
    }
};
