//Problem Statement : https://www.codechef.com/submit/PROBLEMS

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fii for(int i = 0; i < n; i++)
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int p, s;
    cin>>p>>s;
    pair<int, int> diff[p], pdata[s];
    for(int i = 0; i < p; i++){
        for(int j = 0; j < s; j++){
            cin>>pdata[j].first;
        }
        for(int j = 0; j < s; j++){
            cin>>pdata[j].second;
        }
        sort(pdata, pdata+s);
        int k = 0;
        for(int j = 0; j < s-1; j++){
            k += (pdata[j].second > pdata[j+1].second);
        }
        diff[i] = {k, i+1};
    }
    sort(diff, diff+p);
    for(auto i : diff) cout<<i.second<<endl;
return 0;
}