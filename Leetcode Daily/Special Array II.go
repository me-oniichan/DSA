func isArraySpecial(nums []int, queries [][]int) []bool {
    n := len(nums)
    m := len(queries)
    ans := make([]bool, m)
    lastBreaker := -1
    auxArr := make([]int, n)
    auxArr[0] = -1
    for i := 1; i < n; i++ {
        if nums[i]%2 == nums[i-1]%2 {
            lastBreaker = i - 1
        }
        auxArr[i] = lastBreaker
    }
    for i := 0; i < m; i++ {
        l, r := queries[i][0], queries[i][1]
        if auxArr[r] < l {
            ans[i] = true
        } else {
            ans[i] = false
        }
    }

    return ans
}
