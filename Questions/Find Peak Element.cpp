#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fii for(int i = 0; i < n; i++
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int start=0, end=nums.size()-1, size = nums.size()-1;
        while(true){
            int mid = (start+end)/2;
            int left = mid==0?INT_MIN : nums[mid-1];
            int right = mid==size?INT_MIN : nums[mid+1];
            if(left > nums[mid]) end=mid-1;
            else if(right > nums[mid]) start=mid+1;
            else{
                return mid;
            }
        }      
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
return 0;
}