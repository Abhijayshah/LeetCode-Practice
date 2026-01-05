class Solution {
public:
    int magicalString(int n) {

        if (n == 0) return 0;        // Edge case
        if (n <= 3) return 1;        // "122" → only one '1'

        vector<int> s(n + 1);        // Magical string as integer array
        s[0] = 1;
        s[1] = 2;
        s[2] = 2;

        int i = 2;                   // Read pointer (counts)
        int j = 3;                   // Write pointer
        int curr = 1;                // Current number to write (1 or 2)
        int countOnes = 1;           // First '1' already counted

        while (j < n) {

            // Write s[i] times current number
            for (int k = 0; k < s[i] && j < n; k++) {
                s[j] = curr;

                if (curr == 1) {     // Count '1'
                    countOnes++;
                }

                j++;
            }

            // Switch between 1 and 2
            curr = (curr == 1) ? 2 : 1;
            i++;                     // Move read pointer
        }

        return countOnes;
    }
};
