class Solution {
public:
    vector<vector<int>> tree;
    vector<int> xorVal, in, out;
    int timer = 0;

    void dfs(int node, int parent, const vector<int>& nums) {
        in[node] = timer++;
        xorVal[node] = nums[node];

        for (int child : tree[node]) {
            if (child == parent) continue;
            dfs(child, node, nums);
            xorVal[node] ^= xorVal[child];
        }

        out[node] = timer++;
    }

    // Checks if u is ancestor of v
    bool isAncestor(int u, int v) {
        return in[u] <= in[v] && out[v] <= out[u];
    }

    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        tree.assign(n, {});
        xorVal.assign(n, 0);
        in.assign(n, 0);
        out.assign(n, 0);

        for (auto& e : edges) {
            tree[e[0]].push_back(e[1]);
            tree[e[1]].push_back(e[0]);
        }

        dfs(0, -1, nums);  // root the tree at 0
        int totalXOR = xorVal[0];
        int minScore = INT_MAX;

        // Try all pairs of nodes u and v (potential cut points)
        for (int i = 1; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int a = xorVal[i], b = xorVal[j], c;
                if (isAncestor(i, j)) {
                    // i is ancestor of j, so cut j first, then i
                    b = xorVal[j];
                    a = xorVal[i] ^ xorVal[j];
                    c = totalXOR ^ xorVal[i];
                } else if (isAncestor(j, i)) {
                    // j is ancestor of i
                    a = xorVal[i];
                    b = xorVal[j] ^ xorVal[i];
                    c = totalXOR ^ xorVal[j];
                } else {
                    // Disjoint
                    a = xorVal[i];
                    b = xorVal[j];
                    c = totalXOR ^ a ^ b;
                }

                int mx = max({a, b, c});
                int mn = min({a, b, c});
                minScore = min(minScore, mx - mn);
            }
        }

        return minScore;
    }
};
