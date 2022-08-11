// Problem Statement : https://www.codechef.com/submit/SUMPRODSEG

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fii for (int i = 0; i < n; i++)

ll find_factor(ll n)
{
    ll fact = n;
    for (ll i = sqrtl(n); i >= 1; i--)
    {
        if (n % i == 0)
            return i;
    }
    return n;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        ll x, y;
        cin >> x >> y;
        ll set1[2] = {x / 2, x / 2 + (x & 1)};
        ll set2[2] = {find_factor(y)};
        set2[1] = y / set2[0];

        if ((set1[0] <= set2[0] && set1[1] >= set2[0]) || (set1[0] <= set2[1] && set1[1] >= set2[1]) || (set2[0] <= set1[0] && set2[1] >= set1[0]) || (set2[0] <= set1[1] && set2[1] >= set1[1]))
            cout << -1 << endl;
        else
            cout << set1[0] << ' ' << set1[1] << endl
                 << set2[0] << ' ' << set2[1] << endl;
    }
    return 0;
}