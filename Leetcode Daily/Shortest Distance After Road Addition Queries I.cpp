#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    std::vector<int> shortestDistanceAfterQueries(int n, std::vector<std::vector<int>>& queries) {
        std::unordered_map<int, std::set<int>> graph;
        
        for (int i = 0; i < n - 1; ++i) {
            graph[i].insert(i + 1);
        }
        
        std::vector<int> answer;

        auto bfs = [&]() {
            std::vector<int> distance(n, std::numeric_limits<int>::max());
            distance[0] = 0;
            std::queue<int> q;
            q.push(0);
            
            while (!q.empty()) {
                int current = q.front();
                q.pop();
                
                for (int neighbor : graph[current]) {
                    if (distance[neighbor] > distance[current] + 1) {
                        distance[neighbor] = distance[current] + 1;
                        q.push(neighbor);
                    }
                }
            }
            
            return distance[n - 1] == std::numeric_limits<int>::max() ? -1 : distance[n - 1];
        };

        for (const auto& query : queries) {
            int ui = query[0];
            int vi = query[1];
            graph[ui].insert(vi);
            int shortest_path = bfs();
            answer.push_back(shortest_path);
        }
        
        return answer;
    }
};
