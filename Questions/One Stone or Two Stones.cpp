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
        if(x==y){
            if(x&1) cout<<"chef";
            else cout<<"chefina";
        }
        else if(x-y>=2) cout<<"chef";
        else if(y-x>=2) cout<<"chefina";
        else{
            if(abs(x/2+y/2)&1) cout<<"chef";
            else cout<<"chefina";
        }
        cout<<endl;
    }
return 0;
}