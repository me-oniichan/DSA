//Problem Statement : https://www.codechef.com/submit/HLEQN

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
        int x;
        cin>>x;
        bool flag = 0;
        for (int b = 1; b*b <= x; b++){
            int exp = (x-2*b)%(2+b);
            if ((x-2*b)/(2+b) && !exp) {
                flag = 1;
                break;    
            }
        }

        flag? cout<<"YES"<<endl : cout<<"NO"<<endl;
    }
return 0;
}