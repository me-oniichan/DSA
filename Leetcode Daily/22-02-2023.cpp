#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fii for(int i = 0; i < n; i++)

class Solution {
public:
    bool verify(vector<int> &weights, int &k, int &days){
        int sum =0, d = 1;
        for(int i : weights){
            sum+=i;
            if(sum > k){
                d++;
                sum=i;
            };
            if(days < d) return false;
        }
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int right = accumulate(weights.begin(), weights.end(), 0);
        int left = *max_element(weights.begin(), weights.end());

        while(left <= right){
            int mid = (left+right)/2;
            if(verify(weights, mid, days)) right = mid-1;
            else left = mid+1;
        }
        return left;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
return 0;
}