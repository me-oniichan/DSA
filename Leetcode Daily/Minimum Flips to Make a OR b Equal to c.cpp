#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minFlips(int a, int b, int c) {
        int res  = (a|b)^c, ans=0;
        for(int i=0; i < 32; i++){
            if(res&1){
                if(c&1) ans++;
                else{
                    if(a&1) ans++;
                    if(b&1) ans++;
                }
            }
            res>>=1;
            a>>=1;
            b>>=1;
            c>>=1;
        }
        return ans;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
return 0;
}