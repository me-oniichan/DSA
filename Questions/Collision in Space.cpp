// Problem Statement: https://www.codechef.com/submit/COLLIDE

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fii for (int i = 0; i < n; i++)

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x, y;
        char de;
        cin >> x >> y >> de;
        int n, xa, ya;
        vector<float> distance;
        char da;
        cin >> n;
        while (n--)
        {
            cin >> xa >> ya >> da;
            if (da == 'U')
            {
                switch (de)
                {
                case 'U':
                    break;
                case 'D':
                    if (xa == x)
                    {
                        float time = (float(y) - float(ya)) / 2.0;
                        if (time > 0)
                            distance.push_back(time);
                    }
                    break;
                case 'L':
                    if (x > xa && y > ya)
                    {
                        if (x - xa == y - ya)
                            distance.push_back(y - ya);
                    }
                    break;
                case 'R':
                    if (x < xa && y > ya)
                    {
                        if (xa - x == y - ya)
                            distance.push_back(y - ya);
                    }
                    break;
                default:
                    break;
                }
            }
            else if (da == 'D')
            {
                switch (de)
                {
                case 'U':
                    if (xa == x)
                    {
                        float time = (float(ya) - float(y)) / 2.0;
                        if (time > 0)
                            distance.push_back(time);
                    }
                    break;
                case 'D':
                    break;
                case 'L':
                    if (x > xa && ya > y)
                    {
                        if (x - xa == ya - y)
                            distance.push_back(ya - y);
                    }
                    break;
                case 'R':
                    if (xa > x && ya > y)
                    {
                        if (xa - x == ya - y)
                            distance.push_back(ya - y);
                    }
                    break;
                default:
                    break;
                }
            }
            else if (da == 'L')
            {
                switch (de)
                {
                case 'U':
                    if (xa > x && ya > y)
                    {
                        if (xa - x == ya - y)
                            distance.push_back(ya - y);
                    }
                    break;
                case 'D':
                    if (xa > x && y > ya)
                    {
                        if (xa - x == y - ya)
                            distance.push_back(y - ya);
                    }
                    break;
                case 'L':
                    break;
                case 'R':
                    if (ya == y)
                    {
                        float time = (float(xa) - float(x)) / 2.0;
                        if (time > 0)
                            distance.push_back(time);
                    }
                    break;
                default:
                    break;
                }
            }
            else if (da == 'R')
            {
                switch (de)
                {
                case 'U':
                    if (x > xa && ya > y)
                    {
                        if (x - xa == ya - y)
                            distance.push_back(ya - y);
                    }
                    break;
                case 'D':
                    if (x > xa && y > ya)
                    {
                        if (x - xa == y - ya)
                            distance.push_back(y - ya);
                    }
                    break;
                case 'L':
                    if (ya == y)
                    {
                        float time = (float(x) - float(xa)) / 2.0;
                        if (time > 0)
                            distance.push_back(time);
                    }
                    break;
                case 'R':
                    break;
                default:
                    break;
                }
            }
        }
        if (distance.empty()) cout<<"SAFE"<<endl;
        else printf("%.1f\n", float(*min_element(distance.begin(), distance.end())));
    }
    return 0;
}