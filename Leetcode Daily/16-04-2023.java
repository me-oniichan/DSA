class Solution {
    public int numWays(String[] words, String target) {
        int mod = 1000000007;
        int m = target.length(), k = words[0].length();
        int count[][] = new int[26][k];
        for (int j = 0; j < k; j++) {
            for (String word : words) {
                count[word.charAt(j) - 'a'][j]++;
            }
        }
        long dp[][] = new long[m + 1][k + 1];
        dp[0][0] = 1;
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j < k; j++) {
                if (i < m) {
                    dp[i + 1][j + 1] += count[target.charAt(i) - 'a'][j] * dp[i][j];
                    dp[i + 1][j + 1] %= mod;
                }
                dp[i][j + 1] += dp[i][j];
                dp[i][j + 1] %= mod;
            }
        }
        return (int)dp[m][k];
    }
}