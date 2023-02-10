#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fii for(int i = 0; i < n; i++)

class Solution {
public:
    int findMin(vector<int> &nums, int start, int end){
        if(end <= start) return nums[end];
        int mid = (start+end)/2;
        if(nums[end] < nums[mid]) return findMin(nums, mid+1, end);
        else return findMin(nums, start, mid-1);
    }
    int findMin(vector<int>& nums) {
        return findMin(nums, 0, nums.size()-1);
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
return 0;
}