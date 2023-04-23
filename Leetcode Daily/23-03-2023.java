class Solution {
    public int numberOfArrays(String s, int k) {
        int size = s.length(), n =  (int)Math.log10(k)+1;
        int off = (int)Math.pow(10, n-1);
        int[] dp = new int[n+1]; dp[0]=1;
        final int mod = 1000000007;

        for(int i=0; i < size; i++){
            if(s.charAt(i)=='0'){
                dp[i%(n+1)]=0;
                continue;
            }
            long num=0;
            for(int j=i; j < size; j++){
                num = num*10 + (s.charAt(j)-'0');
                if(num > k) break;

                dp[(j+1)%(n+1)] = (dp[(j+1)%(n+1)] + dp[i%(n+1)])%mod;
            }
            dp[i%(n+1)] = 0;

        }

        return dp[size%(n+1)];
    }
}