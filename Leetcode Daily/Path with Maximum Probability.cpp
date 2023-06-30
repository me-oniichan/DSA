#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int, double>>> graph(n);  //{node, probability}
        vector<double> minprob(n);
        minprob[start] = 1;
        int size = succProb.size();

        for (size_t i = 0; i < size; i++){
            graph[edges[i][0]].push_back({edges[i][1], succProb[i]});
            graph[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }

        queue<pair<int, double>> q({make_pair(start, 1)}); //node, probability
        while(!q.empty()){
            auto &p = q.front();

            for(auto &v : graph[p.first]){
                double newprob = p.second*v.second;
                if(newprob > minprob[v.first]){
                    minprob[v.first] = newprob;
                    q.push({v.first, newprob});
                }
            }

            q.pop();
        }
        return minprob[end];
    }
};