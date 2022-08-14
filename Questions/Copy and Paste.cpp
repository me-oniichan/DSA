// Problem Statement : https://www.codechef.com/submit/NCOPIES

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fii for (int i = 0; i < n; i++)

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        string s;
        cin >> s;
        ll sum = 0;
        fii
        {
            if (s[i] == '1')
                sum++;
        }

        if ((sum * m) & 1)
        {
            cout << 0 << endl;
        }
        else if (sum * m == 0)
        {
            cout << n * m << endl;
        }
        else
        {
            ll beg = 0, tar = sum * m / 2;
            for (; m > 0 && beg * sum + sum < tar; m--, beg++);

            ll count = 0, cur = beg * sum;
            for (int _ = 0; _ < min((ll)2, m); _++)
            {
                for (int i = 0; i < n; i++)
                {
                    count += (tar == cur);
                    cur += (s[i] == '1');
                }
            }

            cout << count << endl;
        }
    }
    return 0;
}