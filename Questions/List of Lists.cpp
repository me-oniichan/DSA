//Problem Statement : https://www.codechef.com/submit/LISTLIST

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
        int n, elem;
        cin>>n;
        map<int, int> m;
        // int arr[n];
        fii{
            cin>>elem;
            m[elem]++;
        }
        int front = -1;
        for(auto i : m){
            if (i.second > front && i.second%2 == 0) front = i.second;
        }
        if (front = -1) cout<<-1<<endl;
        else{
            cout<<n-front/2<<endl;
        }
    }
return 0;
}