#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int t;
    cin>>t;
    while (t--) {
        int n,k;
        cin>>n>>k;
        
        vector<int> a(n),b(n);

        for (int i=0; i < n; i++){
            cin>>a[i];
        }

        for (int i=0; i < n; i++){
            cin>>b[i];
        }

        int ans=a[0];
        int cur = 0;
        int maxm = 0;
        for (int i=0; i < min(k, n); i++){
            cur+=a[i];
            maxm = max(maxm, b[i]);
            int points = cur + maxm*(k-i-1);
            ans = max(ans, points);
        }

        cout<<ans<<"\n";
        
    }

    return 0;
}
