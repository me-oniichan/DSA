//Problem Statement : https://www.codechef.com/submit/KLIP?tab=statement
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fii for(int i = 1; i < n; i++)
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        int dp[n] = {0}, sum = 0;

        for (int i = 0; i <= n-k; i++){
            sum += dp[i];
            if (s[i] == '1' && sum%2 == 0){
                dp[i]+=1;
                dp[i+k]-=1;
                sum++;
            }
            else if (s[i] == '0' && sum%2 == 1){
                dp[i]+=1;
                dp[i+k]-=1;
                sum++;
            }
        }
        fii{
            dp[i]+=dp[i-1];
        }
        for(int i = 0; i < n; i++){
            if (dp[i]&1){
                if (s[i] == '0') cout<<'1';
                else cout<<'0';
            }
            else cout<<s[i];
        }
        cout<<endl;
    }
return 0;
}