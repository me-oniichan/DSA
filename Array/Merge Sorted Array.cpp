//Problem Statement : https://leetcode.com/explore/interview/card/top-interview-questions-easy/96/sorting-and-searching/587/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int n1 = m-1, n2 = n-1;
        for(int i = m+n-1; i>=0 && n1>=0 && n2>=0; i--){
            if(nums1[n1]<nums2[n2]){
                nums1[i] = nums2[n2];
                n2--;
            }
            else{
                nums1[i] = nums1[n1];
                n1--;
            }
        }
        if (n1 == -1){
            for(int i = 0; i<=n2;i++) nums1[i] = nums2[i];
        }
    }
}; 
 
int main(){
    
 
return 0;
}