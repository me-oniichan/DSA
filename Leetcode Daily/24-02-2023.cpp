#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fii for(int i = 0; i < n; i++)

class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int minm=INT_MAX;
        priority_queue<int> q;
        for(int i : nums){
            i = (i&1)?(i<<1):i;
            q.push(i);
            minm = min(i, minm);
        }
        int ans=INT_MAX;
        while(!(q.top()&1)){
            ans = min(ans, q.top()-minm);
            minm = min(minm, q.top()/2);
            q.push(q.top()/2);
            q.pop();
        }
        return min(ans, q.top()-minm);
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
return 0;
}