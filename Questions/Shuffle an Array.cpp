//Problem Statement : https://leetcode.com/explore/interview/card/top-interview-questions-easy/98/design/670/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> original;
    vector<int> re;
    long seed = 1000000007;
    Solution(vector<int>& nums) {
        original = nums;
        re = nums;
    }
    
    vector<int> reset() {
        return re;
        // for(int i = 0;i<re.size(); i++) original[i] = re[i];
    }

    int get_random(){
        int digits = rand();
        seed = (digits^seed);
        return seed%original.size();
    }
    
    vector<int> shuffle() {
        for(int i = 0; i<original.size();i++){
            int rand = get_random();
            swap(original[rand], original[i]);
        }
        return original;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
return 0;
}