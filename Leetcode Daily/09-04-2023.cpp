#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fii for(int i = 0; i < n; i++)

class Solution {
public:
    string s;
    vector<vector<int>> graph;
    vector<bool> visited;
    vector<vector<int>> dp;
    unordered_set<int> uset;
    bool flag=true;

    void dfs(int node){
        vector<int> &ref = dp[node];
        uset.insert(node);
        visited[node] = true;
        for(int i : graph[node]){
            if(!visited[i]){
                dfs(i);
                for(int j=0; j<26; j++){
                    ref[j] = max(ref[j], dp[i][j]);
                }
            }else{
                if(uset.count(i)==1){
                    flag=false;
                    return;
                }else{
                    for(int j=0; j<26; j++){
                        ref[j] = max(ref[j], dp[i][j]);
                    }
                }
            }
        }
        uset.erase(node);
        ref[s[node]-'a']++;
    }

    int largestPathValue(string colors, vector<vector<int>>& edges) {
        s = colors;
        graph.resize(colors.size());
        visited.resize(colors.size());
        dp.resize(colors.size(), vector<int>(26));

        for(auto &i : edges){
            graph[i[0]].push_back(i[1]);
        }

        int ans=0;

        for(int i=0; i<colors.size();i++){
            if(!flag) return -1;
            if(!visited[i]){
                uset.clear();
                uset.insert(i);
                dfs(i);
                for(int j=0; j < 26; j++){
                    ans=max(ans, dp[i][j]);
                }
            }
        }
        if(!flag) return -1;
        return ans;

    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
return 0;
}