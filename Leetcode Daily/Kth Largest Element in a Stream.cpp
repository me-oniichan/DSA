#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fii for(int i = 0; i < n; i++)

class KthLargest {
public:
    priority_queue<int, vector<int>,greater<int>> pq;
    int k;
    KthLargest(int k, vector<int>& nums) : k(k) {
        sort(nums.begin(), nums.end(), greater<int>());
        int lim = min((int)nums.size(), k);
        for(int i =0; i < lim; i++) pq.push(nums[i]);
    }
    
    int add(int val) {
        if(pq.size() < k){
            pq.push(val);
            return pq.top();
        }
        int k = pq.top();
        if(k>=val) return k;
        pq.pop();
        pq.push(val);
        return pq.top();
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
return 0;
}