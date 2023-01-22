#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fii for(int i = 0; i < n; i++)

class Solution {
public:
    // bool makeStringsEqual(string s, string target) {
    //     queue<int> set, reset;
    //     int ones=0;
    //     for(int i = 0; i < s.length(); i++){
    //         if(s[i] != target[i]){
    //             if(s[i] == '0') reset.push(i);
    //             else set.push(i);
    //         };
    //         if(s[i] == '1') ones++;
    //     }
    //     while(!reset.empty()){
    //         int i = reset.front();
    //         reset.pop();
    //         if(ones<1) return false;
    //         ones++;
    //     }
    //     while(!set.empty()){
    //         int i = set.front();
    //         set.pop();
    //         if(ones<2) return false;
    //         ones--;
    //     }
    //     return true;
    // }
    bool makeStringsEqual(string s, string target) {
        int ones = 0, set=0, reset=0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] != target[i]){
                if(s[i]=='0') reset++;
                else set++;
            }
            if(s[i]=='1') ones++;
        }
        if(set==0 && reset==0) return true;
        if(ones < 1) return false;

        if(ones<=set && reset == 0) return false;
        return true;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
return 0;
}