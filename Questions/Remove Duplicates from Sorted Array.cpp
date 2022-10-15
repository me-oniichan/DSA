//Problem Statement : https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/727/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fii for(int i = 0; i < n; i++)

    int removeDuplicates(vector<int>& nums) {
        int unique = 0, traverse = 1;
        for(; traverse < nums.size(); traverse++){
            if (nums[traverse-1] != nums[traverse]){
                nums[++unique] = nums[traverse];
            }
        }

        nums.resize(unique+1);
        return nums.size();
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

    removeDuplicates(array);
    for(auto i: array){
        cout<<i<<' ';
    }
return 0;
}