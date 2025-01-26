#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> graph;
    vector<int> visited;
    vector<int> indegree;
    int ans = 0;
    int ans_with_l2cycle = 0;
    
    int get_max_depth(int node){
        int max_depth = 0;
        for(int i : graph[node]){
            if (visited[i] == 0){
                visited[node] = 1;
                max_depth = max(max_depth, get_max_depth(i));
            }
        }
        return max_depth + 1;
    }

    int dfs(int node, int depth){
        visited[node] = depth;
        for(int i : graph[node]){
            if(!visited[i] && indegree[i] != 0){
                dfs(i, depth + 1);
            } else if(indegree[i] != 0) {
                int cycle = depth - visited[i] + 1;
                if (cycle > 2){
                    ans = max(ans, cycle);
                } else {
                    int max_depth = get_max_depth(i);
                    int max_depth2 = get_max_depth(node);
                    cout<<i<<" "<<node<<endl;
                    ans_with_l2cycle += max_depth + max_depth2;
                } 
            }
        }
        return depth;
    }
    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();
        graph.resize(n); 
        visited.resize(n, 0);
        indegree.resize(n, 0);

        for(int i = 0; i < n; i++){
            graph[favorite[i]].push_back(i);
            indegree[favorite[i]]++;
        }

        queue<int> q;
        for(int i = 0; i < n; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            int next = favorite[node];
            indegree[next]--;
            if(indegree[next] == 0){
                q.push(next);
            }
        }

        for(int i = 0; i < n; i++){
            // cout<<indegree[i]<<" ";
            if(!visited[i] && indegree[i] != 0){
                dfs(i, 1);
            }
        }

        return max(ans, ans_with_l2cycle);
    }
};
