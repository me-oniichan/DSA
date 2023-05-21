#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int shortestBridge(vector<vector<int>> &grid)
    {
        int size = grid.size();

        int x = 0, y = 0;

        // find first island
        for (int i = 0; i < size; i++)
        {
            bool flag = 0;
            for (int j = 0; j < size; j++)
            {
                if (grid[i][j] == 1)
                {
                    x = i;
                    y = j;
                    flag = true;
                    break;
                }
            }
            if (flag)
                break;
        }

        deque<pair<int, int>> q({{x, y}});
        deque<pair<int, int>> bridge({{x, y}});
        grid[x][y] = -1;

        // finding boundary of first island
        while (!q.empty())
        {
            auto &p = q.front();
            q.pop_front();
            vector<pair<int, int>> cords = {{p.first - 1, p.second}, {p.first + 1, p.second}, {p.first, p.second + 1}, {p.first, p.second - 1}};
            for (size_t i = 0; i < 4; i++)
            {
                if (cords[i].first >= 0 && cords[i].first < size && cords[i].second >= 0 && cords[i].second < size && grid[cords[i].first][cords[i].second] == 1)
                {
                    q.push_back(cords[i]);
                    bridge.push_back(cords[i]);
                    grid[cords[i].first][cords[i].second] = -1;
                }
            }
        }

        // multisource bfs to find min distance
        int ans = 0;

        while (!bridge.empty())
        {
            for (int len = bridge.size(); len > 0; len--)
            {
                auto &p = bridge.front();
                bridge.pop_front();

                for (auto cords : vector<pair<int, int>>({{p.first - 1, p.second}, {p.first + 1, p.second}, {p.first, p.second + 1}, {p.first, p.second - 1}}))
                {
                    if (cords.first >= 0 && cords.first < size && cords.second >= 0 && cords.second < size)
                    {
                        if (grid[cords.first][cords.second] == 1)
                            return ans;
                        else if (grid[cords.first][cords.second] == 0)
                        {
                            bridge.push_back(cords);
                            grid[cords.first][cords.second] = -1;
                        }
                    }
                }
            }
            ans++;
        }

        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }

    cout << Solution().shortestBridge(grid);

    return 0;
}