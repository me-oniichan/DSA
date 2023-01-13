//Problem Statement : https://leetcode.com/problems/longest-path-with-different-adjacent-characters/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fii for(int i = 0; i < n; i++)

class Solution {
public:
    vector<vector<int>> graph;
    int maxm = 1;
    int dfs(int n, string &s){
        if (graph[n].size() == 0) return 1;
        int path = 1;
        int max1=0, max2=0;

        for(int i : graph[n]){
            int len = dfs(i, s);
            if (len > max1 && s[i] != s[n]) {
                max2 = max1;
                max1 = len;
            }
            else if (len > max2 && s[i] != s[n]) max2 = len;
        }
        path+=(max1+max2);
        if (path > maxm) maxm = path;
        return max1+1;
    }
    int longestPath(vector<int>& parent, string &s) {
        graph.resize(parent.size());
        for(int i = 1; i < parent.size(); i++) graph[parent[i]].push_back(i);
        dfs(0, s);
        return maxm;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
return 0;
}