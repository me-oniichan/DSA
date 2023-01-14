#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fii for(int i = 0; i < n; i++)

class Solution {
public:
    vector<vector<int>> graph;
    bool visited[26] = {0};

    int dfs(int n, vector<int> &chars){
        chars.push_back(n);
        visited[n] = 1;
        
        int m = n;
        for(int i : graph[n]){
            if(visited[i]) continue;
            m = min(m, dfs(i, chars));
        }
        return m;
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        graph.resize(26);
        for(int i = 0; i < s1.length(); i++){
            graph[s1[i] - 'a'].push_back(s2[i]-'a');
            graph[s2[i] - 'a'].push_back(s1[i]-'a');
        }

        char minmap[26];

        for(int i = 0; i < 26; i++){
            if(visited[i]) continue;
            vector<int> chars;
            char m = dfs(i,chars)+'a';
            for(int c : chars) minmap[c] = m;
        }

        for(char&c : baseStr) c= minmap[c-'a'];
        
        return baseStr;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
return 0;
}