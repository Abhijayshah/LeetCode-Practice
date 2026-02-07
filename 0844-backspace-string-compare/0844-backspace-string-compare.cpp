class Solution {
public:
string process(string s) {
    string res;
    for (char ch : s) {
        if (ch == '#') {
            if (!res.empty())
                res.pop_back();
        } else {
            res.push_back(ch);
        }
    }
    return res;
}

bool backspaceCompare(string s, string t) {
    return process(s) == process(t);
}

};