#include <bits/stdc++.h>
#include <cmath>
#include <queue>
using namespace std;

class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq;
        for(int i=0;i<gifts.size();i++){
            pq.push(gifts[i]);
        }
        long long sum=0;
        for(int i=0;i<k;i++){
            int top=pq.top();
            top = floor(sqrt(top));
            pq.pop();
            pq.push(top);
        }
        while(!pq.empty()){
            sum+=pq.top();
            pq.pop();
        }
        return sum;
    }

};
