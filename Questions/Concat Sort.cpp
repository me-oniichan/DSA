//Problem Statement : https://www.codechef.com/JULY222C/problems/CONCATSORT?tab=statement

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
        vector<int> arr(n);
        fii{
            cin>>arr[i];
        }
        vector<int> copy = arr;
        sort(arr.begin(), arr.end());

        vector<int> p, q;
        int ptr=0;
        fii{
            if (copy[i] == arr[ptr]){
                p.push_back(copy[i]);
                ptr++;
            }
            else{
                q.push_back(copy[i]);
            }
        }

        p.insert(p.end(), q.begin(), q.end());
        if (p == arr) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
return 0;
}