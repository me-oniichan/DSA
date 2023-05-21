#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fii for(int i = 0; i < n; i++)


class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int size = graph.size();
        unordered_set<int> g1, g2;
        queue<int> q;

        for(int i=0;i < size; i++){
            if(!g1.count(i) && !g2.count(i)){
                q.push(i);
                g1.insert(i);
                while(!q.empty()){
                    auto &v = graph[q.front()];

                    if(g1.count(q.front())){
                        for(int n : v){
                            if(g1.count(n)) return false;
                            
                            if(!g2.count(n)){
                                g2.insert(n);
                                q.push(n);
                            }
                        }
                    }
                    else{
                        for(int n : v){
                            if(g2.count(n)) return false;
                            
                            if(!g1.count(n)){
                                g1.insert(n);
                                q.push(n);
                            }
                        }
                    }
                    q.pop();
                }
            }
        } 
        return true;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
return 0;
}