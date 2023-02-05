#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fii for(int i = 0; i < n; i++)

class Solution {
public:
    int check(int m1[], int m2[]){
        for(int i=0; i < 26; i++){
            if(m1[i] < m2[i]) return 1;
            else if(m1[i] > m2[i]) return -1;
        }
        return 0;
    }
    vector<int> findAnagrams(string s2, string s1) {
        int m[26] = {0}, m1[26]={0},m2[26]={0};
        for(char c : s1) m[c-'a']++;
        m2[s2[0]-'a'] = 1;
        vector<int> ans;
        for(int i=-1,j=0; j<s2.length();){
            int r[26];
            for(int i=0;i < 26;i++) r[i]= m2[i]-m1[i];
            int x = check(r,m);
            if(x==0){
                ans.push_back(++i);
                if(i < s2.size()) m1[s2[i]-'a']++;
            }
            else if(x==-1){
                if(++i < s2.size()) m1[s2[i]-'a']++;
            }
            else {
                if(++j < s2.size()) m2[s2[j]-'a']++;
            }
        }
        return ans;
    }
}; 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s1,s2;
    cin>>s1>>s2;

return 0;
}