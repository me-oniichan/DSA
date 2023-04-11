#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fii for(int i = 0; i < n; i++)

class Solution {
public:
    string removeStars(string s) {
        string ans="";
        for(char i : s){
            if(i!='*') ans.push_back(i);
            else if (ans.size()>1) ans.pop_back();
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