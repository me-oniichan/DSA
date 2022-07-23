//Problem Statement : https://www.codechef.com/JULY222C/problems/SUMOFPROD1

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
        ll elem, prev = 0, sum = 0;
        fii{
            cin>>elem;
            if (elem){
                prev++;
            }
            else{
                sum+=(prev * (prev+1)/2);
                prev=0;
            }
        }
        sum+=(prev * (prev+1)/2);
        cout<<sum<<endl;
    }
return 0;
}