func lenLongestFibSubseq(arr []int) int {
    n := len(arr)
    m := make(map[int]int)
    for i := 0; i < n; i++ {
        m[arr[i]] = i
    }
    dp := make([][]int, n)
    for i := 0; i < n; i++ {
        dp[i] = make([]int, n)
    }
    ans := 0
    for i := 0; i < n; i++ {
        for j := i + 1; j < n; j++ {
            dp[i][j] = 2
            x := arr[j] - arr[i]
            if x < arr[i] && m[x] != 0 {
                dp[i][j] = dp[m[x]][i] + 1
            }
            ans = max(ans, dp[i][j])
        }
    }
    if ans < 3 {
        return 0
    }
    return ans
}
