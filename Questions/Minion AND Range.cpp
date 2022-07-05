//Problem Statement : https://www.codechef.com/submit/MINIAND

#include <iostream>
using namespace std;
#define ll long long
#define fii for(int i = 0; i < n; i++)

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;

    while(t--){
        int n,q, l, r;
        cin>>n;
        int dp[n+1], elem;
        dp[0] = 0;
        fii{
            cin>>elem;
            if (elem&1) dp[i+1] = dp[i];
            else dp[i+1] = dp[i]+1;
        }
        cin>>q;
        while (q--)
        {
            cin>>l>>r;
            if (dp[r] == dp[l-1]) cout<<"ODD"<<endl;
            else cout<<"EVEN"<<endl;
        }
    }
    return 0;
}