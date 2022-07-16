//Problem Statement : https://www.codechef.com/submit/EQDIFFER

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
        map<int, int> m;
        int elem;
        fii{
            cin>>elem;
            m[elem]++;
        }
        int maxm = 0;
        for(auto i : m){
            if (i.second > maxm) maxm = i.second;
        }
        if (n < 3) cout<<0<<endl;
        else if (maxm < 3) cout<< n- 2<<endl;
        else cout<<n-maxm<<endl;
    }
return 0;
}