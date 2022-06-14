#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fii for(int i = 0; i < n; i++)
 
ll power(ll x, ll y){
    if (y == 0) return 1;
    else if (y&1) return x * power(x, y / 2) * power(x, y / 2);
    else return power(x, y / 2) * power(x, y / 2);
}

int main(){
    int t;
    cin>>t;
    while(t--){
        ll x,y;
        cin>>x>>y;
        if (x == 0 && y == 0) cout<<0<<endl;
        else if (x==0 || y==0) cout<<-1<<endl;
        else{
            ll moves = abs(int(log2(x) - log2(y)));
            ll num = min(x,y)*power(2, moves);
            cout<<moves+max(x,y) + (num != max(x,y))<<endl;
        }
    }
return 0;
}