#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> ans(n, 0);
        for (int i = 0; i < roads.size(); i++) {
            ans[roads[i][0]]++;
            ans[roads[i][1]]++;
        }
        priority_queue<int> maxheap;
        for (int i = 0; i < ans.size(); i++) {
            maxheap.push(ans[i]);
        }
        long long value = 0;
        while (!maxheap.empty()) {
            long long top = maxheap.top();
            maxheap.pop();
            value=value+(top)*n;
            n--;
        }
        return value;
    }
};
