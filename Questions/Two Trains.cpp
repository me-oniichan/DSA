//Problem Statement : https://www.codechef.com/submit/TWOTRAINS?tab=statement

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
        int max = 0, elem;
        ll sum=0;
        while(--n){
            cin>>elem;
            if (elem > max) max = elem;
            sum+=elem;
        }

        cout<<sum + max<<endl;
    }
return 0;
}