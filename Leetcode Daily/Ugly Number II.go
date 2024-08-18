var dp [1690]int;
var p2, p3, p5 int
var lastpos int = 0
func nthUglyNumber(n int) int {
    dp[0] = 1
    if (dp[n-1] == 0){
        for i := lastpos+1; i < n; i++ {
            dp[i] = min(dp[p2]*2, min(dp[p3]*3, dp[p5]*5))
            if dp[i] == dp[p2]*2 {
                p2++
            }
            if dp[i] == dp[p3]*3 {
                p3++
            }
            if dp[i] == dp[p5]*5 {
                p5++
            }
        }
        lastpos = n-1
    }
    return dp[n-1]
}
