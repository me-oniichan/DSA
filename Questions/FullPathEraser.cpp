//Problem statement : https://www.codechef.com/problems/FPE

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fii for(i; i < n; i++)

ll dfs(ll gcd[], ll sums[], int arr[], int key, unordered_map<int, vector<int>> &m, int p){
    if (m[key].size() == 1 && key !=1) return gcd[key] = arr[key-1];

    vector<int> children = m[key];
    ll g = arr[key-1], val; 
    for (int i = 0; i < children.size(); i++){
        if (children[i] == p) continue;
        val = dfs(gcd, sums, arr, children[i], m, key);
        g = __gcd(g, val);
        sums[key] += val;
    }
    return gcd[key] = g;
}

ll maxbeauty = 0;

void beauty(ll gcd[], ll sums[], unordered_map<int, vector<int>> &m, int key, ll pb, int p){
    ll beaut = sums[key] + pb - gcd[key];
    for (int i : m[key]){
        if (i == p) continue;
        beauty(gcd, sums, m, i, beaut, key);
    }
    maxbeauty = max(beaut, maxbeauty);
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        unordered_map<int, vector<int>> m;
        int i = 0; fii{
            cin>>arr[i];
        }

        int parent, child;
        i =1; fii{
            cin>>parent>>child;
            m[parent].push_back(child);
            m[child].push_back(parent);
        }

        ll gcd[n+1] ={0}; ll sums[n+1] = {0};
        dfs(gcd, sums, arr, 1, m, 0);
        beauty(gcd, sums, m, 1, gcd[1], 0);
        cout<<maxbeauty<<endl;
        maxbeauty = 0;
    }
return 0;
}