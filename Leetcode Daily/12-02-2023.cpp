#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fii for(int i = 0; i < n; i++)

class Solution {
public:
    vector<vector<int>> graph;
    long long fuel=0;
    double seats;
    int dfs(int node, int p){
        int reps=1;
        for(int n : graph[node]){
            if(n==p) continue;
            reps+=dfs(n, node);
        }
        fuel+=ceil(reps/seats);
        return reps+1;
    }

    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        graph.resize(roads.size()+1);
        this->seats = seats;
        for(auto&i : roads){
            graph[i[0]].push_back(i[1]);
            graph[i[1]].push_back(i[0]);
        }
        dfs(0,0);
        return fuel;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
return 0;
}