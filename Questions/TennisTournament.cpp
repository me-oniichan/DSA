//Problem Statement: https://www.codechef.com/submit/EXUNB

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fii for(int i = 1; i <= n; i++)
 
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if ((n&1) == 0) cout<<"NO"<<endl;
        else{
            cout<<"YES"<<endl;
            fii{
                int arr[n] = {0};
                for(int j = i; j <   (i + n/2); j++){
                    arr[j%n] = 1;
                }
                for(int k : arr) cout<<k;
                cout<<endl;
            }
        }
    }   
return 0;
}