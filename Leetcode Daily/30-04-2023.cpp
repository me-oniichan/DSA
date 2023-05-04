#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fii for(int i = 0; i < n; i++)

class UnionFind {
public:
    vector<int> group;
    vector<int> rank;
    int components;
    UnionFind(int size) {
        group = vector<int>(size);
        rank = vector<int>(size);
        for (int i = 0; i < size; ++i) {
            group[i] = i;
        }
        components=size;
    }

    int find(int node) {
        if (group[node] != node) {
            group[node] = find(group[node]);
        }
        return group[node];
    }

    void join(int node1, int node2) {
        int group1 = find(node1);
        int group2 = find(node2);

        if (group1 == group2) {
            return;
        }

        if (rank[group1] > rank[group2]) {
            group[group2] = group1;
        } else if (rank[group1] < rank[group2]) {
            group[group1] = group2;
        } else {
            group[group1] = group2;
            rank[group2] += 1;
        }
        components--;
    }

    bool areConnected(int node1, int node2) {
        int group1 = find(node1);
        int group2 = find(node2);
        return group1 == group2;
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        if(edges.size() < n-1) return -1;
        UnionFind uf1(n+1);
        UnionFind uf2(n+1);
        int ans = 0;

        sort(edges.begin(), edges.end(), [](vector<int>& a, vector<int>&b){
            return a[0] > b[0];
        });

        for(auto&v : edges){
            if(v[0]==1){
                if(uf1.areConnected(v[1],v[2])) ans++;
                else uf1.join(v[1], v[2]);
            }else if(v[0]==2){
                if(uf2.areConnected(v[1],v[2])) ans++;
                else uf2.join(v[1], v[2]);
            }else{
                if(uf1.areConnected(v[2], v[1]) && uf2.areConnected(v[2], v[1])) ans++;
                else{
                    uf2.join(v[2], v[1]);
                    uf1.join(v[2], v[1]);
                }
            }   
        }
        if(uf1.components>2 || uf2.components >2) return -1;
        return ans;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
return 0;
}