#include <bits/stdc++.h>
using namespace std;

int m = 200;

map<pair<int, int>, double> dp;

double cal(int i, int j)
{
    return (dp[{max(0, i - 4), j}] + dp[{max(0, i - 3), j - 1}] + dp[{max(0, i - 2), max(0, j - 2)}] + dp[{i - 1, max(0, j - 3)}]) / 4;
};

void coolfunc()
{
    dp[{0, 0}] = 0.5;

    for (int k = 1; k <= m; k++)
    {
        dp[{0, k}] = 1;
        dp[{k, 0}] = 0;
        for (int j = 1; j <= k; j++)
        {
            dp[{j, k}] = cal(j, k);
            dp[{k, j}] = cal(k, j);
        }
    }
}

bool timed = true;
class Solution
{
public:
    Solution()
    {
        if (timed)
        {
            coolfunc();
            timed = false;
        }
    }

    double soupServings(int n)
    {
        int v = ceil(n / 25);
        if (v > 200)
            return 1;
        else
            return dp[{v, v}];
    }
};