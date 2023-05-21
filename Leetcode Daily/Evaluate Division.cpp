#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fii for(int i = 0; i < n; i++)

class Solution {
public:
    unordered_map<string, int> v_i;
    vector<string> v;
    double graph[29][29]={0};
    int v_size=0;

    void find_graph(vector<vector<string>>& equations, vector<double>& values, int n)
    {
        int x, y;
        for(int i=0; i<n; i++){
            vector<string> e=equations[i];
            if (v_i.count(e[0])==0){
                v.push_back(e[0]);
                v_i[e[0]]=v_size++;
            }
            if (v_i.count(e[1])==0){
                v.push_back(e[1]);
                v_i[e[1]]=v_size++;
            }
            x=v_i[e[0]];
            y=v_i[e[1]];
            graph[x][x]=1;
            graph[y][y]=1;
            graph[x][y]=values[i];
            graph[y][x]=1/values[i];
        }
    }

    void dfs(int x, unordered_set<int>& visited){
        visited.insert(x);
        for(int y=0; y<v_size; y++){
            if (graph[x][y]!=0  && visited.count(y)==0){
                double w=graph[x][y];
                visited.insert(y);
                for (int z=0; z<v_size; z++){
                    if (graph[y][z]!=0  && visited.count(z)==0){
                        double w2=graph[y][z];
                        graph[x][z]=w*w2;
                        graph[z][x]=1.0/graph[x][z];
                    }
                }
            }
        }
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n=values.size();
        find_graph(equations, values, n);

        int m=queries.size();
        for(int x=0; x<v_size; x++){
            unordered_set<int> visited;
            dfs(x, visited);
        }

        vector<double> ans(m , -1);
        for(int i=0; i<m; i++){
            vector<string> q=queries[i];
            if (v_i.count(q[0])!=0 && v_i.count(q[1])!=0){
                int c=v_i[q[0]], d=v_i[q[1]];
                if (graph[c][d]!=0)
                    ans[i]=graph[c][d];
            } 
        }
        return ans;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
return 0;
}