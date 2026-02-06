class Solution {
public:
vector<vector<int>> largeGroupPositions(string s) {
    vector<vector<int>> ans;
    int n = s.size();

    for (int i = 0; i < n; i++) {
        int j = i;
        while (j < n && s[j] == s[i]) j++;

        if (j - i >= 3)
            ans.push_back({i, j - 1});

        i = j - 1; // skip processed group
    }
    return ans;
}

};