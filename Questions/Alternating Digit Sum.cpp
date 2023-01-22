#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fii for(int i = 0; i < n; i++)

class Solution {
public:
    int alternateDigitSum(int n) {
        int re = 0;
        while(n){
            re*=10;
            re += (n%10);
            n/=10;
        }
        bool parity = 0;
        int a = 0, b=0;
        while(re){
            int digit = re%10;
            if(parity == 0){
                a+=digit;
                parity = 1;
            }
            else{
                b+=digit;
                parity = 0;
            }
            re/=10;
        }
        return a-b;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
return 0;
}