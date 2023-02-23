#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fii for(int i = 0; i < n; i++)

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        map<int, vector<int>> m; //key : capital, value : profits
        priority_queue<int> q;
        int size = capital.size();

        for(int i = 0; i < size; i++) m[capital[i]].push_back(profits[i]);

        int maxProf=w;
        while(k){
            for(auto&i : m){
                if(i.first <= maxProf){
                    for(int&i : i.second) q.push(i);
                    m.erase(i.first);
                }else break;
            }
            if(q.empty()) break;
            maxProf+=q.top();
            q.pop();
            k--;
        }
        return maxProf;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
return 0;
}