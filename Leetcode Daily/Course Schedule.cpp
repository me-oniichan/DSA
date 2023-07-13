#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> graph;
    vector<bool> visited;
    vector<bool> stacktrace;
    bool dfs(int node){
        if(stacktrace[node]) return true;
        if(visited[node]) return false;

        stacktrace[node] = true;
        visited[node] = true;

        for(int i : graph[node]){
            if(dfs(i)){
                return true;
            }
        }
        stacktrace[node] = false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        graph.resize(numCourses);
        visited.resize(numCourses);
        stacktrace.resize(numCourses);

        for(auto&v : prerequisites){
            graph[v[0]].push_back(v[1]);
        }

        for(int i=0; i < numCourses; i++){
            if(dfs(i)){
                return false;
            }
        }
        return true;
    }
};