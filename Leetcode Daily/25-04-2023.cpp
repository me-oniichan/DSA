#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fii for(int i = 0; i < n; i++)

class SmallestInfiniteSet {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<bool> present;
    SmallestInfiniteSet() {
        present.resize(1000, true);
        for(int i=1; i<=1000; i++) pq.push(i);
    }
    
    int popSmallest() {
        int x = pq.top();
        pq.pop();
        present[x-1] = false;
        return x;
    }
    
    void addBack(int num) {
        if(!present[num-1]) pq.push(num);
        present[num-1]=true;
    }
};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
return 0;
}