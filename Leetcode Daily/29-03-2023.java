import java.util.Arrays;

class Solution {
    public int maxSatisfaction(int[] satisfaction) {
        int ans=0, sum=0;
        Arrays.sort(satisfaction);
        for(int i=satisfaction.length-1; i>=0; i--){
            sum+=satisfaction[i];
            if(sum>=0){
                ans+=sum;
            }
        }      
        return ans;       
    }
}