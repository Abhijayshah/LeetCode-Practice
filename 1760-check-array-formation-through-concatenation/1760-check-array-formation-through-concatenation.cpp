#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        unordered_map<int, vector<int>> mp;
        
        // Map first element of each piece to the whole piece
        for (auto &piece : pieces) {
            mp[piece[0]] = piece;
        }
        
        int i = 0, n = arr.size();
        while (i < n) {
            if (mp.find(arr[i]) == mp.end()) {
                return false; // no piece starts with arr[i]
            }
            vector<int> &piece = mp[arr[i]];
            for (int num : piece) {
                if (i >= n || arr[i] != num) return false;
                i++;
            }
        }
        return true;
    }
};
