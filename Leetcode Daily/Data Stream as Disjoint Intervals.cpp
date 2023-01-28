#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fii for(int i = 0; i < n; i++)

class SummaryRanges {
public:
    set<int> s;
    SummaryRanges() {
    }
    
    void addNum(int value) {
        s.insert(value);
    }
    
    vector<vector<int>> getIntervals() {
        if(s.empty()) return {{}};
        vector<vector<int>> v;
        vector<int> e(2);
        int prev= *s.begin();
        e = {prev, prev};
        for(int i : s){
            if(i > prev+1){
                v.push_back(e);
                e = {i,i};
            }
            else e[1] = i;
            prev = i;
        }
        v.push_back(e);
        return v;
    }
};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
return 0;
}