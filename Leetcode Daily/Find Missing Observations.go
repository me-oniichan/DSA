func missingRolls(rolls []int, mean int, n int) []int {
    m := len(rolls)
    sum := mean * (m + n)
    for _, r := range rolls {
        sum -= r
    }
    if sum < n || sum > 6*n {
        return []int{}
    }
    res := make([]int, n)
    for i := 0; i < n; i++ {
        res[i] = min(6, sum-n+i+1)
        sum -= res[i]
    }
    return res
}
