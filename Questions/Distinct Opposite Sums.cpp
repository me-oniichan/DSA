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
        int arr[n],j=1;
        for(int i=0; i < n/2; i++){
            arr[i]=j++;
            arr[n-1-i]=j++;
        }
        for(int i : arr) cout<<i<<" ";
        cout<<endl;
    }
    
return 0;
}