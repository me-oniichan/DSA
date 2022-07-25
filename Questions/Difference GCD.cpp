// Problem Statement : https://www.codechef.com/JULY222C/problems/DIF_GCD

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fii for (int i = 0; i < n; i++)

bool isPrime(int n)
{
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
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
        int n, m;
        cin >> n >> m;
        int a,b;
        if (m < 2*n) cout<<m<<' '<<m<<endl;
        else if(m%n == 0) cout << n << ' ' << m << endl;
        else{
            int max_ = (m >= 2*n)? 2*n : m/2;
            int min_ = 0;
            for ( int i = n; i < max_+1; i++){
                int multi = m/i;
                int cd = (i*multi) -i;
                if (cd > min_){
                    min_=cd;
                    a = i;
                    b = (i*multi);
                }
            }
            cout<<a<<' '<<b<<endl;
        }
    }
    return 0;
}