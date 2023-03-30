class Solution {
    public boolean isScramble(String s1, String s2) {
        Boolean[][][] memo = new Boolean[s1.length()][s2.length()][s1.length() + 1];
        return helper(s1, s2, 0, 0, s1.length(), memo);
    }

    public boolean helper(String s1, String s2, int i, int j, int len, Boolean[][][] memo) {
        if (memo[i][j][len] != null) {
            return memo[i][j][len];
        }
        if (len == 1) {
            return memo[i][j][len] = s1.charAt(i) == s2.charAt(j);
        }
        for (int k = 1; k < len; k++) {
            if (helper(s1, s2, i, j, k, memo) && helper(s1, s2, i + k, j + k, len - k, memo)) {
                return memo[i][j][len] = true;
            }
            if (helper(s1, s2, i, j + len - k, k, memo) && helper(s1, s2, i + k, j, len - k, memo)) {
                return memo[i][j][len] = true;
            }
        }
        return memo[i][j][len] = false;
    }
}