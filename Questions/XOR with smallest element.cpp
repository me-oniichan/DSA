//Problem Statement : https://www.codechef.com/submit/SMALLXOR?tab=statement

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fii for(int i = 0; i < n; i++)
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        ll n, x, y, elem;
        cin>>n>>x>>y;
        multiset<ll> s;
        fii{
            cin>>elem;
            s.insert(elem);
        }
        // elem = *s.begin();
        // cout<<(x^elem)<<endl;
        while(y--){
            ll min = *s.begin();
            if ((min ^ x) > *s.begin()){
                s.insert(min^x);
                s.erase(s.begin());
            }
            else{
                if ((y&1) == 0){
                    min = x^*s.begin();
                    s.erase(s.begin());
                    s.insert(min);
                }
                break;
            }
        }

        for(auto i : s) cout<<i<<' ';
        cout<<endl;
    }
return 0;
}