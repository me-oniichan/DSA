#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fii for(int i = 0; i < n; i++)

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> mod(k);
        int sum = 0;
        for(int &i : nums){
            sum+=i;
            mod[(sum%k+k)%k]++;
        }
        int subarrays=0;
        mod[0]+=1;

        for(int i: mod) subarrays+=(i*(i-1)/2);

        return subarrays;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
return 0;
}