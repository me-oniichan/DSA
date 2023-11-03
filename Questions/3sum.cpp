//Problem Statement : https://leetcode.com/explore/interview/card/top-interview-questions-medium/103/array-and-strings/776/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fii for(int i = 0; i < n; i++)

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if(nums.size() <3 || nums[0]>0) return {};

        unordered_map<int, int> hmap;
        for(int i = 0; i < nums.size(); i++) hmap[nums[i]] = i;

        vector<vector<int>> result;
        for(int i=0; i < nums.size()-2; i++){
            if (nums[i] > 0) break;

            for(int j = i+1; j < nums.size()-1; j++){
                int req = -1*(nums[i] + nums[j]);
                if(hmap.count(req) && hmap[req] > j){
                    result.push_back({nums[i], nums[j], req});
                    j = hmap[nums[j]];
                }
            }
            i = hmap[nums[i]];
        }
	   
        return result;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
return 0;
}
