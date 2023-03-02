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
        if(x%2==0) cout<<(y-x+(y&1))/2;
        else{
            if(x%3==0) x+=3;
            else if(x%5==0) x+=5;
            else if(x%7==0) x+=7;
            cout<<(y-x+(y&1))/2 +1;
        }
        cout<<endl;
    }
return 0;
}