#include <bits/stdc++.h>
using namespace std;

class SnapshotArray {
public:
    vector<vector<pair<int, int>>> snaps;
    int snapid;
    SnapshotArray(int length) {
        snapid=0;
        snaps.resize(length, vector<pair<int, int>>({make_pair(0,0)}));
    }
    
    void set(int index, int val) {
        snaps[index].push_back(make_pair(snapid, val));
    }
    
    int snap() {
        return snapid++; 
    }
    
    int get(int index, int snap_id) {
        auto val = upper_bound(snaps[index].begin(), snaps[index].end(), make_pair(snap_id, INT_MAX));
        return prev(val)->second;
    }
};