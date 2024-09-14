func xorQueries(arr []int, queries [][]int) []int {
    n := len(arr)
    prefix := make([]int, n+1)
    for i := 1; i <= n; i++ {
        prefix[i] = prefix[i-1] ^ arr[i-1]
    }
    res := make([]int, len(queries))
    for i, q := range queries {
        res[i] = prefix[q[0]]^prefix[q[1]+1]
    }
    return res
}
