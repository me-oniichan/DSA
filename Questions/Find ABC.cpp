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
        ll n;
        cin>>n;
        ll arr[n+1],a=0,b=0,c=0;
        fii{
            cin>>arr[i];
        }
        cin>>arr[n];

        for (ll i = (1<<int(log2(n))); i > 0; i>>=1){
            ll df = arr[0] - arr[i];
            int cart = abs(df)/i;
            if (df > 0){
                if (cart==1){
                    cart = 2;
                    if ((a^i) <= n){
                        a^=i;
                        cart--;
                    }
                    if (cart && ((b^i) <= n)){
                        b^=i;
                        cart--;
                    }
                    if (cart && ((c^i) <=n)) c^=i;
                }
                else if (cart == 3){
                    a^=i;
                    b^=i;
                    c^=i;
                }
            }
            else{
                if (cart == 1){
                    if ((a^i) <= n) a^=i;
                    else if ((b^i) <= n) b^=i;
                    else c^=i;
                }
            }
            ll list[3] = {a,b,c};
            sort(list, list+3);
            a= list[0]; b = list[1]; c = list[2];
        }
        cout<<a<<" "<<b<<" "<<c<<endl;
    } 
return 0;
}