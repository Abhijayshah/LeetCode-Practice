#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

class SnapshotArray {
public:
    vector<vector<pair<int, int>>> snaps;
    int snap_id;

    SnapshotArray(int length) {
        snaps.resize(length);
        snap_id = 0;
        // Initialize each index with (snap_id 0, value 0)
        for (int i = 0; i < length; i++) {
            snaps[i].push_back({0, 0});
        }
    }
    
    void set(int index, int val) {
        // If last entry for this index has the same snap_id, overwrite it
        if (snaps[index].back().first == snap_id) {
            snaps[index].back().second = val;
        } else {
            snaps[index].push_back({snap_id, val});
        }
    }
    
    int snap() {
        return snap_id++;
    }
    
    int get(int index, int snap_id_req) {
        const auto& vec = snaps[index];
        // Binary search to find largest snap_id <= snap_id_req
        int left = 0, right = vec.size() - 1;
        int res = 0;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (vec[mid].first <= snap_id_req) {
                res = vec[mid].second;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return res;
    }
};
