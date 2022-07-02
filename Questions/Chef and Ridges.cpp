//Problem Statement: https://www.codechef.com/submit/PRDRG

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fii for(int i = 1; i < n; i++)
 
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        while (cin>>n)
        {
            int y = pow(2, n);
            int x = 1;
            fii{
                if (i&1) x = x*2 -1;
                else x = x*2 +1;
            }
            cout<<x<<' '<<y<<' ';
        }
        
    }
return 0;
}