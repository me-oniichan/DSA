#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    while (t--) {
        int n,k;
        cin>>n>>k;
        vector<int> ans(n);

        for (int i=0; i < n; i++){
            ans[i]=i+1;
        }

        reverse(ans.begin()+k, ans.end());

        for(int i : ans){
            cout<<i<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
