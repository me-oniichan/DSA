#include <array>
#include <utility>
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>> > pq;
        array<array<int, 2>, 4> dir = {{{0, 1}, {0, -1}, {1, 0}, {-1, 0}}};
        pq.push({0, {0, 0}});

        while (!pq.empty()) {
            auto [cost, pos] = pq.top();
            pq.pop();
            int x = pos.first;
            int y = pos.second;
            if (x == n - 1 && y == m - 1) {
                return cost;
            }
            if (grid[x][y] == -1) {
                continue;
            }
            int temp = grid[x][y];
            grid[x][y] = -1;
            for (int i = 0; i < 4; i++) {
                int nx = x + dir[i][0];
                int ny = y + dir[i][1];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                    int new_cost = cost + (i + 1 == temp ? 0 : 1);
                    pq.push({new_cost, {nx, ny}});
                }
            }
        }

        return -1;
    }
};
