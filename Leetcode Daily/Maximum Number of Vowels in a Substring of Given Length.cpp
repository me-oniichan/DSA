#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fii for(int i = 0; i < n; i++)

static bool isVowel(char c){
    if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u') return true;
    return false;
}

class Solution {
public:
    int maxVowels(string s, int k) {
        int ans=0, fans=0;
        for(int i=0; i<k; i++){
            if(isVowel(s[i])) ans++;
        }
        fans = ans;
        for(int i=1; i < s.length()-k+1;i++){
            if(isVowel(s[i-1])) ans--;
            if(isVowel(s[i+k-1])) ans++;
            fans = max(fans, ans);
        }

        return fans;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin>>s;
    cout<<Solution().maxVowels(s,7);
}