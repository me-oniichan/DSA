#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fii for(int i = 0; i < n; i++)

class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int size = nums1.size();
        vector<pair<int, int>> temp(size);
        for(int i=0; i< size; i++){
            temp[i] = {nums1[i], nums2[i]};
        }
        sort(temp.begin(), temp.end(), [](pair<int, int>&a,pair<int, int>&b){
            return a.second > b.second;
        });
        priority_queue<int, vector<int>, greater<int>> pq;
        long long ans=0, sum=0;

        for(int i=0; i<k; i++){
            pq.push(temp[i].first);
            sum+=temp[i].first; 
        }

        ans = sum*temp[k-1].second;

        for(int i=k; i < size; i++){
            sum += temp[i].first-pq.top();
            pq.pop();
            pq.push(temp[i].first);
            ans = max((sum)*temp[i].second, ans);
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