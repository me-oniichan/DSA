//Problem Statement : https://www.codechef.com/submit/MAGICJAR?tab=statement

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
     int n;
     cin>>n;
     ll jars =0, ai;
     fii{
         cin>>ai;
         jars+=(ai-1);
     }
     cout<<jars+1<<endl;
    }
return 0;
}