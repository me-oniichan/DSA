#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fii for(int i = 0; i < n; i++)

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<vector<int>>> graph(n, vector<vector<int>>(2)); //node, color
        vector<vector<int>> visisted(n, vector<int>(2)); // red blue
        vector<int> answer(n, -1);
        int dist = 0;

        for(auto i : redEdges) graph[i[0]][0].push_back(i[1]);
        for(auto i : blueEdges) graph[i[0]][1].push_back(i[1]);


        queue<pair<int, bool>> q({{0,0}, {0,1}});
        while(!q.empty()){
            queue<pair<int, bool>> q2;
            while(!q.empty()){
                pair<int, bool> node = q.front();
                visisted[node.first][node.second]=1;
                answer[node.first] = answer[node.first]==-1? dist : answer[node.first];
                for(auto elem : graph[node.first][!node.second]){
                    if(!visisted[elem][!node.second]) q2.push({elem, !node.second});
                }
                q.pop();
            }
            q=q2;
            dist++;
        }
        return answer;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
return 0;
}