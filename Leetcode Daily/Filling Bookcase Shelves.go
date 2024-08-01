func minHeightShelves(books [][]int, shelf_width int) int {
    n := len(books)
    dp := make([]int, n+1)
    dp[0] = 0
    for i := 1; i <= n; i++ {
        width := 0
        height := 0
        dp[i] = 1<<31 - 1
        for j := i; j > 0; j-- {
            width += books[j-1][0]
            if width > shelf_width {
                break
            }
            height = max(height, books[j-1][1])
            dp[i] = min(dp[i], dp[j-1]+height)
        }
    }
    return dp[n]
}
