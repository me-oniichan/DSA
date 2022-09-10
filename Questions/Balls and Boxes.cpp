//Problem Statement : https://www.codechef.com/submit/BALLBOX
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
        int n, k;
        cin>>n>>k;
        if (2*n >= k*(k+1)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
return 0;
}