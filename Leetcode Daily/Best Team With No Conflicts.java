import java.util.*;;
class Solution {
    public int bestTeamScore(int[] scores, int[] ages) {
        int ans=0, n=scores.length;
        int[][] arr = new int[n][2];

        for(int i = 0; i < n; i++){
            arr[i][0] = ages[i];
            arr[i][1] = scores[i];
        }

        int[] dp = new int[n];

        Arrays.sort(arr, (a,b) -> a[0] == b[0] ? a[1]-b[1] : a[0]-b[0]);
        for(int i = 0; i < n; i ++){
            for(int j=0; j<=i; j++){
                if(arr[j][1] <= arr[i][1]){
                    dp[i] = Math.max(dp[i], dp[j]+arr[j][1]);
                }
            }
            if(dp[i] > ans) ans = dp[i];
        }
        return ans;
    }
}