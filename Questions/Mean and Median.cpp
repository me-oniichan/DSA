//Problem Statement : https://www.codechef.com/submit/MEANMEDIAN

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
        int x,y;
        cin>>x>>y;
        int a = (3*x - 2*y);
        cout<<y <<' '<<y<<' '<<a<<endl;
    }
return 0;
}