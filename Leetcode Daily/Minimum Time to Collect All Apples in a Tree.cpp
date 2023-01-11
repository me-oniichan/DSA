//Problem Statement : https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fii for(int i = 0; i < n; i++)

class Solution {
public:
    int time = 0;
    unordered_map<int, vector<int>> m;
    bool dfs(int v, int p, vector<bool>& hasApple){
        vector<int> &children = m[v];
        int apples = 0;
        if (!children.size()) return hasApple[v];
        for(int i : children){
            if (i==p) continue;
            apples += dfs(i,v, hasApple);
        }
        time+=apples;
        return apples || hasApple[v]? 1 : 0;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        for(auto i : edges) {
            m[i[0]].push_back(i[1]);
            m[i[1]].push_back(i[0]);
        }
        dfs(0,0, hasApple);
        return time*2;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
return 0;
}