#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<bool> visited;
    vector<bool> gvisited;

    bool dfs(int node, vector<vector<int>>&graph){
        auto& gval = graph[node];
        gvisited[node]=true;
        for(int i : gval){
            if(visited[i]){
                return true;
            }
            else if(gvisited[i]){
                return false;
            }
            else{
                visited[i] = 1;
                if(dfs(i, graph)){
                    return true;
                }
                visited[i] = false;
            }
        }
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int size = graph.size();
        visited.resize(size);
        gvisited.resize(size);

        for(int i=0; i < size; i++){
            if(!gvisited[i]) {
                visited[i] = true;
                if(!dfs(i, graph)){
                    visited[i] = false;
                };
            }
        }

        vector<int> ans;
        for(int i=0; i< size; i++){
            if(!visited[i]) ans.push_back(i);
        }

        return ans;
    }
};