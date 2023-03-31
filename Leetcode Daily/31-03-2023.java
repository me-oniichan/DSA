class Solution {
    public int ways(String[] pizza, int k) {
        int m = 1000000007, row= pizza.length, col= pizza[0].length();
        int dp[][][]= new int[row][col][k], apple[][]= new int[row+1][col+1];

        for(int i=row-1; i>=0; i--){
            for(int j= col-1; j >=0; j--){
                apple[i][j] = (pizza[i].charAt(j)=='A'?1:0) + apple[i+1][j]+apple[i][j+1]-apple[i+1][j+1];
                dp[i][j][0] = apple[i][j] > 0 ? 1 : 0;
            }
        }

        for (int remain = 1; remain < k; remain++) {
            for (int i = 0; i < row; i++) {
                for (int j = 0; j < col; j++) {
                    for (int next_row = i + 1; next_row < row; next_row++) {
                        if (apple[i][j] - apple[next_row][j] > 0) {
                            dp[i][j][remain] += dp[next_row][j][remain - 1];
                            dp[i][j][remain] %= m;
                        }
                    }
                    for (int next_col = j + 1; next_col < col; next_col++) {
                        if (apple[i][j] - apple[i][next_col] > 0) {
                            dp[i][j][remain] += dp[i][next_col][remain - 1];
                            dp[i][j][remain] %= m;
                        }
                    }
                }
            }
        }

        return dp[0][0][k-1];
    }
}