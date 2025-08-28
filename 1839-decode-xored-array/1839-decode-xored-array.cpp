class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> arr;
        arr.push_back(first);  // First element is given
        
        // For each encoded element, calculate the next array element
        for (int i = 0; i < encoded.size(); i++) {
            // arr[i+1] = arr[i] XOR encoded[i]
            int next = arr[i] ^ encoded[i];
            arr.push_back(next);
        }
        
        return arr;
    }
};