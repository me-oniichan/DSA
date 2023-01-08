#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fii for(int i = 0; i < n; i++)

class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> q;
        for(int &i : nums){
            q.push(i);
        }
        long long score = 0;
        while(k--){
            long num = q.top();
            score+= num;
            q.pop();
            q.push(ceil((float)num/3.0));
        }
        return score;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Solution sol;
    vector<int> v{756902131,995414896,95906472,149914376,387433380,848985151};
    cout<<sol.maxKelements(v, 6);
return 0;
}