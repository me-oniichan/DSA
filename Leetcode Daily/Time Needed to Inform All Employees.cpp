#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> graph(n, vector<int>());
        for(int i = 0; i < n; i++){
            if(i == headID) continue;
            graph[manager[i]].push_back(i);
        }
        int maxtime = 0;
        queue<pair<int, int>> q({{headID, 0}}); //node, time
        while(!q.empty()){
            auto& node = q.front();
            int time = node.second + informTime[node.first];
            for(int i : graph[node.first]){
                q.push({i, time});
            }
            maxtime = max(node.second, maxtime);
            q.pop();
        }
        return maxtime;
    }
};
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
return 0;
}