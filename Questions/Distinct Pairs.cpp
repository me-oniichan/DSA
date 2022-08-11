//Problem Statement : https://www.codechef.com/submit/DPAIRS?tab=statement
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fii for(int i = 0; i < n; i++)


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    cin>>n>>m;
    int minA = 0, maxB = 0, elem, mm;
    cin>>mm;
    for(int i = 1; i < n; i++){
        cin>>elem;
        if (mm > elem){
            mm = elem;
            minA = i;
        }
    }
    cin>>mm;
    for(int i = 1; i < m; i++){
        cin>>elem;
        if (mm < elem){
            mm = elem;
            maxB = i;
        }
    }

    for(int i = 0; i < m; i++) cout<<minA <<' '<< i<<endl;
    for(int i = 0; i < n; i++) if(i != minA) cout<<i << ' '<< maxB<<endl;
    
return 0;
}