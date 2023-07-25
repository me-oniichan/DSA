#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int left=0, right = arr.size()-1;

        while(left < right){
            int mid = (left+right)/2;

            if(arr[mid] > arr[left]){
                if(arr[mid] > arr[mid-1]) left = mid;
                else right = mid-1;
            }
            else{
                if(arr[mid] > arr[mid+1]) right = mid;
                else left = mid+1;
            }
        }
        return left;
    }
};