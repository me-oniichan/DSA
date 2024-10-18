func countMaxOrSubsets(nums []int) int {
    dp := make([]int, 1<<17)
    dp[0] = 1
    max := 0
    for _, num := range nums {
        max |= num
    }
    for _, num := range nums {
        for i := max; i >= 0; i-- {
            if dp[i] > 0 {
                dp[i|num] += dp[i]
            }
        }
    }
    return dp[max]    
}
