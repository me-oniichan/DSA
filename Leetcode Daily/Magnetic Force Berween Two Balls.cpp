#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    bool check(vector<int>& position, int mid, int m) {
        int cnt = 1, pre = position[0];
        for (int i = 1; i < position.size(); i++) {
            if (position[i] - pre >= mid) {
                cnt++;
                pre = position[i];
            }
        }
        return cnt >= m;
    }

    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int n = position.size();
        int l = 1, r = ceil(position[n - 1] / (m - 1.0));
        while (l < r) {
            int mid = (r - l) / 2 + l;
            if (check(position, mid, m)) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return l - 1;
    }
};
