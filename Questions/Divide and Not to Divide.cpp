//Problem Statement : https://www.codechef.com/JULY222C/problems/DIVAB?tab=statement

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
        int a,b,n;
        cin>>a>>b>>n;
        if (a%b == 0) cout<<-1<<endl;
        else{
            if (n%a){
                int multi= n/a + 1;
                cout<<(multi + ((multi*a)%b == 0))*a<<endl;
            }
            else{
                int multi= n/a;
                cout<<(multi + (n%b == 0))*a<<endl;
            }
        }
    }
return 0;
}