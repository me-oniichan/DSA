#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fii for(int i = 0; i < n; i++)

class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
       vector<vector<pair<int, int>>> graph(n+1);
       for(auto i : roads){
           graph[i[0]].push_back({i[1], i[2]});
           graph[i[1]].push_back({i[0], i[2]});
       }
        queue<int> q; vector<bool> visited(n+1);
        q.push(1); visited[1] = true;
        int mindist=INT_MAX;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto i : graph[node]){
                if(!visited[i.first]){
                    visited[i.first] = true;
                    q.push(i.first);
                }
                mindist = min(mindist, i.second);
            }
        }
       return mindist;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
return 0;
}