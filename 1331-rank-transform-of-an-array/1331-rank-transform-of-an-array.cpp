class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {

        // Step 1: Create a copy of the array
        vector<int> sortedArr = arr;

        // Step 2: Sort the copied array
        sort(sortedArr.begin(), sortedArr.end());

        // Step 3: Map each unique value to its rank
        unordered_map<int, int> rank;
        int currentRank = 1;

        for (int num : sortedArr) {
            // Assign rank only if number not seen before
            if (rank.find(num) == rank.end()) {
                rank[num] = currentRank;
                currentRank++;
            }
        }

        // Step 4: Replace elements with their ranks
        for (int i = 0; i < arr.size(); i++) {
            arr[i] = rank[arr[i]];
        }

        return arr;
    }
};
