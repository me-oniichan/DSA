//Problem Statement : https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fii for(int i = 0; i < n; i++)

class Solution {
public:

    int lb(int start, int end, int& val, vector<int>& array){
        if (start > end) return start;
        int mid = (start+end)/2;
        if(array[mid]==val) return lb(start, mid-1, val, array);
        else return lb(mid+1, end, val, array);
    }
    int ub(int start, int end, int& val, vector<int>& array){
        if (start > end) return end;
        int mid = (start+end)/2;
        if(array[mid]==val) return ub(mid+1, end, val, array);
        else return ub(start, mid-1, val, array);
    }

    int binarySearch(int start, int end, int& val, vector<int>& array){
        if(start > end) return -1;
        int mid = (start+end)/2;
        if (array[mid] == val) return mid;
        else if (array[mid] < val) return binarySearch(mid+1, end, val, array);
        else return binarySearch(start, mid-1, val, array);
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int i = binarySearch(0, nums.size()-1, target, nums);
        if (i==-1) return {-1, -1};
        return {lb(0, i, target, nums), ub(i, nums.size()-1, target, nums)};
    }
}; 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
return 0;
}