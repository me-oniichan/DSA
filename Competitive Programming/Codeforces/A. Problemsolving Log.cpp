#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    int t;
    cin>>t;
    while (t--) {
        int n;
        string s;
        cin>>n;
        cin>>s;
        
        vector<int> map(26);
        
        for (char c : s){
            map[c - 'A']++;
        }

        int ans = 0;
        
        for (int i=0; i < 26; i++){
            if (i+1 <= map[i]) ans++;
        }

        cout<<ans<<endl;
    }

    return 0;
}
