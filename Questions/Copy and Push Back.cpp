// Problem Statement : https://www.codechef.com/submit/COPYPUSH

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fii for (int i = 0; i < n; i++)

void solve()
{
    int n;
    cin >> n;
    string s, ans = "";
    cin >> s;

    while(n){
        if (s.substr(0, n/2) != s.substr(n/2, n/2)){
            cout<<"NO"<<endl;
            return;
        }
        n = (n - (n&1))/2;
    }
    cout<<"YES"<<endl;
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
        solve();
    }
    return 0;
}