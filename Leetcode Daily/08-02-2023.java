import java.util.*;
class Solution {
    public int jump(int[] nums) {
        int i=0, jumps=0,size = nums.length;
        while(i<size){
            int max=0;
            for(int j=1; j <= nums[i]; j++){
                if(nums[i+j]==nums[size-1]) return jumps+1;
                max = nums[max] < nums[i+j]+j? i+j : max;
            }
            jumps++;
            i=max;
        }
        return 0;
    }
}