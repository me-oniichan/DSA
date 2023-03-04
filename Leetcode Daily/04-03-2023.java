class Solution {
    public long countSubarrays(int[] nums, int minK, int maxK) {
        long subs=0;
        int l=-1, mn=-1, mx=-1;
        for(int i =0 ; i < nums.length; i++){
            if(nums[i]<=maxK && nums[i]>=minK){
                if(minK==nums[i]) mn=i;
                if(maxK==nums[i]) mx=i;
                
            }else l=i;

            int smol = Math.min(mx, mn);
            if(smol>l)subs+=(smol-l);
        }
        return subs;
    }
}