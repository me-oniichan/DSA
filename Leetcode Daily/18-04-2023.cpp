#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fii for(int i = 0; i < n; i++)

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans;
        int size = min(word1.size(), word2.size());
        for(int i=0; i < size;i++){
            ans.push_back(word1[i]);
            ans.push_back(word2[i]);
        }
        ans+=word1.substr(size);
        ans+=word2.substr(size);
        return ans;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
return 0;
}