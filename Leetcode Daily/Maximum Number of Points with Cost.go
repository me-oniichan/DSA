func maxPoints(points [][]int) int64{
    n, m := len(points), len(points[0])
    dp := make([]int64, m)
    for i := 0; i < n; i++ {
        newDp := make([]int64, m)
        leftMax := int64(0)
        for j := 0; j < m; j++ {
            leftMax = max(leftMax-1, dp[j])
            newDp[j] = leftMax
        }
        rightMax := int64(0)
        for j := m-1; j >= 0; j-- {
            rightMax = max(rightMax-1, dp[j])
            newDp[j] = max(newDp[j], rightMax)
        }
        for j := 0; j < m; j++ {
            newDp[j] += int64(points[i][j])
        }
        dp = newDp
    }
    var res int64
    for _, v := range dp {
        res = max(res, v)
    }
    return res
}
