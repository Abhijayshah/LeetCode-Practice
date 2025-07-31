class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> res;  // to store all distinct ORs
        unordered_set<int> cur;  // to store ORs of subarrays ending at current index

        for (int num : arr) {
            unordered_set<int> next;
            next.insert(num);

            for (int prev : cur) {
                next.insert(prev | num);
            }

            cur = next;

            for (int val : cur) {
                res.insert(val);
            }
        }

        return res.size();
    }
};
