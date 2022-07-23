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
        int x,y,n,r;
        cin>>x>>y>>n>>r;

        if (x*n > r) cout<<-1<<endl;
        else{
            int prem = (r-x*n)/(y-x);
            int reg = n-prem;
            if (prem >= n) cout<<0<<' '<<n<<endl;
            else cout<<reg<<' '<<prem<<endl;
        }
    }
return 0;
}