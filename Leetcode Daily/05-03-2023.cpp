#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fii for(int i = 0; i < n; i++)

class Solution {
public:
    int minJumps(vector<int>& arr) {
        int size = arr.size(), jumps=1;
        if(size==1) return 0;
        unordered_map<int, unordered_set<int>> graph;
        vector<vector<int>> subgraph(size);
        for(int i= 0; i <size; i++){
            graph[arr[i]].insert(i);
        }
        for(int i= 0; i <size; i++){
            if(i>0) subgraph[i].push_back(i-1);
            if(i<size-1) subgraph[i].push_back(i+1);
        }

        queue<int> q({0,-1});
        vector<bool> visited(size);
        visited[0]=1;
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            if(cur==-1){
                jumps++;
                q.push(-1);
                continue;
            }

            for(int i : graph[arr[cur]]){
                if(i==size-1) return jumps;
                if(!visited[i]){
                    visited[i]=1;
                    q.push(i);
                }
            }
            graph.erase(arr[cur]);
            for(int i : subgraph[cur]){
                if(i==size-1) return jumps;
                if(!visited[i]){
                    visited[i]=1;
                    q.push(i);
                }
            }
        }
        return jumps;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
return 0;
}