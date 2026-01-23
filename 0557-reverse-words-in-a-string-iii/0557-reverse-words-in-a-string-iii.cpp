class Solution {
public:
string reverseWords(string s) {
    string result = "";
    string word = "";

    for (char c : s) {
        if (c == ' ') {
            reverse(word.begin(), word.end());
            result += word + " ";
            word = "";
        } else {
            word += c;
        }
    }

    reverse(word.begin(), word.end());
    result += word;

    return result;
}

};