#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    int t;
    cin>>t;
    while (t--) {
        int n;
        cin>>n;
        string s;
        cin>>s;

        int ans = 1;
        
        for (int i=n-2; i >= 0; i--){
            ans+=1;
            for(int j = i+1; j < n; j++){
                if (s[i] == s[j]){
                    break;
                }
                ans+=1;
            }
        }


        cout<<ans<<"\n";
    }
}
