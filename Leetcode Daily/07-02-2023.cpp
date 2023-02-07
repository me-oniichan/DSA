#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fii for(int i = 0; i < n; i++)

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> m;
        int maxm=0;
        int i=-1, j=0;
        while(j < fruits.size()){
            m[fruits[j]]++;
            while(m.size() > 2){
                m[fruits[++i]]--;
                if(m[fruits[i]]==0) m.erase(fruits[i]);
            }
            int sum=0;
            for(auto v : m) sum+=v.second;
            maxm = max(maxm, sum);
            j++;
        }
        return maxm;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
return 0;
}