#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fii for(int i = 0; i < n; i++)

class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        unordered_set<string> m[26];

        for(string s : ideas) m[s[0]-'a'].insert(s.substr(1));
        long long sum=0;
        for(int i = 0; i < 26; i++){
            for(int j=i+1; j < 26; j++){
                int a = 0;
                for(string suffix : m[i]){
                    if(m[j].count(suffix)) a++;
                }
                sum+=(m[i].size()-a)*(m[j].size()-a);
            }
        }
        return sum*2;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
return 0;
}