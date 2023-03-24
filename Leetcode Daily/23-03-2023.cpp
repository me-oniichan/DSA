#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fii for(int i = 0; i < n; i++)

class UnionFind{
    vector<int> parent;
    public:
        UnionFind(int n){
            parent.resize(n);
            for(int i = 0; i < n; i++){
                parent[i]=i;
            }
        }
        int find(int key){
            if(parent[key]!=key) parent[key] = find(parent[key]);
            return parent[key];
        }

        void set(int key, int value){
            int parkey = find(parent[key]), parval = find(parent[value]);
            parent[parval] =  parkey;
        }
        
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n-1) return -1;
        int groups = n;

        UnionFind uf(n);
        for(auto i : connections){
            if(uf.find(i[0]) != uf.find(i[1])){
                uf.set(i[0], i[1]);
                groups--;
            }
        }
        return groups-1;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
return 0;
}