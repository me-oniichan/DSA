//Problem Statement

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fii for(int i = 0; i < n; i++)

ll countState(map<ll, ll> &m, int n){
    ll sum = n/2 + n/3 + n/4;
    if (sum <= n){
        return n; 
    }

    else if (m.find(n) != m.end())
    {
        return m[n];
    }
    else{
        return m[n] = countState(m, n/2) + countState(m, n/3) + countState(m, n/4);
    }
}

int main(){
    int n;
    while(cin>>n){
        map<ll, ll> m;
        cout<<countState(m,n)<<endl;
    }
return 0;
}