//Problem Statement : https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/564/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fii for(int i = 0; i < n; i++)

    int maxProfit(vector<int>& nums) {
        int profit = 0;
        for(size_t i = 0; i< nums.size()-1; i++){
            if(nums[i] < nums[i+1]) profit+= nums[i+1] - nums[i];
        }
        return profit;
    }

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<int> array;
    int elem;
    while(cin>>elem){
        array.push_back(elem);
    }

    maxProfit(array);
    for(auto i: array){
        cout<<i<<' ';
    }
return 0;
}