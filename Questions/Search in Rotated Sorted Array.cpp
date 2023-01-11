//Problem Statement : https://leetcode.com/problems/search-in-rotated-sorted-array/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fii for(int i = 0; i < n; i++)

class Solution {
public:
    int findPivot(int start, int end, vector<int>& nums){
        if(start > end) return end;
        int mid = (start+end)/2;
        if(nums[mid] > nums[0]) return findPivot(mid+1, end, nums);
        else return findPivot(start, mid-1, nums);
    }
    int binarySearch(int start, int end, int& val, vector<int>& array){
        if(start > end) return -1;
        int mid = (start+end)/2;
        if (array[mid] == val) return mid;
        else if (array[mid] < val) return binarySearch(mid+1, end, val, array);
        else return binarySearch(start, mid-1, val, array);
    }
    int search(vector<int>& nums, int target) {
        int p = findPivot(0, nums.size()-1, nums);
        if (nums.size()==1) p=0;
        if(nums[0] < target) return binarySearch(p+1, nums.size()-1, target, nums);
        else return binarySearch(0, p, target, nums);
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
return 0;
}