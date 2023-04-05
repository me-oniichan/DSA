class Solution {
    public int minimizeArrayValue(int[] nums) {
        int ans=nums[0];
        long sum = nums[0];
        for(int i=1; i < nums.length; i++){
            sum+=nums[i];
            ans = (int)Math.max(ans, (sum+i)/(i+1));
        }
        return ans;       
    }
}