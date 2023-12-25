#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main(){

    int t;
    cin>>t;

    while (t--) {
        int n,k,d;
        cin>>n>>k>>d;

        vector<int> a(n), b(k);
        
        for(int i=0; i < n; i++) cin>>a[i];
        for(int i=0; i < k; i++) cin>>b[i];

        int ans = 0;
        for(int i=0; i < min(d, 2*n+1); i++){
            int c = 0;
            for(int j=0; j < n; j++) c+=a[j]==j+1;

            c+=(d-i-1)/2;

            ans = max(ans, c);

            for(int j=0; j < b[i%k]; j++){
                a[j]++;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
