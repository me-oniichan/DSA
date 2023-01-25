#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fii for(int i = 0; i < n; i++)

class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int mindist = INT_MAX, d=0, node=-1;
        vector<int> reachable(edges.size(), -1);
        vector<bool> visited(edges.size());

        while(!visited[node1]){
            reachable[node1] = d++;
            visited[node1] = 1;
            if(edges[node1]==-1) break;
            node1 = edges[node1];
        }
        visited.clear();
        visited.resize(edges.size());
        d = 0;
        while(!visited[node2]){
            if(reachable[node2]!=-1){
                int dist = max(reachable[node2], d);
                if(mindist > dist){
                    mindist = dist;
                    node = node2;
                }
                else if(mindist == dist) node = min(node, node2);
            }
            d++;
            visited[node2] = 1;
            if(edges[node2]==-1) break;
            node2 = edges[node2];
        }
        return node;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
return 0;
}