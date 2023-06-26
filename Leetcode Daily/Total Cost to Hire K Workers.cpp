#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int n) {
        int size = costs.size();
         priority_queue<int, vector<int>, greater<int>> leftq, rightq;
        int left = n-1, right = max(n, size-n);

        for(size_t i = 0; i <= left; i++) leftq.push(costs[i]);
        for(size_t i = right; i < size; i++) leftq.push(costs[i]);

        long long ans=0;
        while(k--){
            int a = leftq.empty()? INT_MAX : leftq.top(), b = rightq.empty()? INT_MAX : rightq.top();

            if(a <= b){
                ans+=a;
                leftq.pop();
                if(right-left>1){
                    left++;
                    leftq.push(costs[left]);
                }
            }else{
                ans+=b;
                rightq.pop();
                if(right-left > 1){
                    right--;
                    rightq.push(costs[right]);
                }
            }
        }
        return ans;
    }
};
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
return 0;
}