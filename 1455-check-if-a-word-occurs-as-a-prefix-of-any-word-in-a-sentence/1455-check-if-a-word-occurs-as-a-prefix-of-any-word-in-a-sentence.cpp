class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int n = sentence.size();
        int i = 0, index = 1;

        while (i < n) {
            int j = i;

            // move j to end of word
            while (j < n && sentence[j] != ' ') j++;

            string word = sentence.substr(i, j - i);

            if (word.find(searchWord) == 0) {
                return index;
            }

            index++;
            i = j + 1; // move to next word
        }

        return -1;
    }
};