class Solution {
    public int profitableSchemes(int n, int minProfit, int[] group, int[] profit) {
        int size = group.length;
        final int m = 1000000007;
        int[][][] dp = new int[size+1][n+1][minProfit+1];

        for (int count = 0; count <= n; count++) {
            dp[size][count][minProfit] = 1;
        }

        for(int i=size-1; i >= 0; i--){
            for(int count = 0; count <= n; count++){
                for(int prof=0; prof <=minProfit; prof++){
                    dp[i][count][prof] = dp[i+1][count][prof];

                    if(count+group[i] <= n) dp[i][count][prof] = (dp[i][count][prof]+dp[i+1][count+group[i]][Math.min(minProfit, prof + profit[i])])%m;
                }
            }
        }
        return dp[0][0][0];
    }
}