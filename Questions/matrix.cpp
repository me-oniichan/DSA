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
        int n, m, d;
        cin >> n >> m;
        if (n >= m)
        {
            d = m+1;
            fii
            {
                for (int j = 0; j < m; j++)
                {
                    cout << i+1 + j*d << ' ';
                }
                cout<<endl;
                d++;
            }
        }
        else{
            d = 1;
            fii{
                for (int j = 0; j < m; j++){
                    cout<< i*(n+1) + 1 + (j)*d<<' ';
                }
                cout<<endl;
                d++;
            }
        }
    }
    return 0;
}