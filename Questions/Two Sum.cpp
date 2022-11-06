#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fii for(int i = 0; i < n; i++)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, vector<int>> m;
        vector<int> result;
        for(int i = 0; i < nums.size(); i++) m[nums[i]].push_back(i);

        for(int i : nums){
            if(m.find(target-i) != m.end()){
                if(target-i == i && m[i].size() >1){
                    result.push_back(m[i][0]);
                    result.push_back(m[i][1]);
                    break;
                }
                else if(target-i != i){
                    result.push_back(m[i][0]);
                    result.push_back(m[target-i][0]);
                    break;
                }
            }
        }
        return result;
    }
};

int main(){
    vector<int> nums;
    int elem;
    while(cin>>elem) nums.push_back(elem);
    int target = nums[nums.size()-1];
    nums.resize(nums.size()-1);

    Solution sol;
    for(int i : sol.twoSum(nums, target)) cout<<i<<' ';
return 0;
}