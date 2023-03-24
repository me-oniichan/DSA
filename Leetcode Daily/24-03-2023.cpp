#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fii for(int i = 0; i < n; i++)

class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, bool>>> graph(n); // next node, direction
        for(auto i : connections){
            graph[i[0]].push_back({i[1], true});
            graph[i[1]].push_back({i[0], false});
        }
        int paths=0;
        queue<int> q({0}); vector<bool> visited(n);
        visited[0] = true;
        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto i : graph[node]){
                if(!visited[i.first]){
                    visited[i.first] = true;
                    if(i.second) paths++;
                    q.push(i.first);
                }
            }
        }
        return paths;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
return 0;
}