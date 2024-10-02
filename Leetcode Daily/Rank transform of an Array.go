func arrayRankTransform(arr []int) []int {
    n := len(arr)
    sorted := make([]int, n)
    copy(sorted, arr)
    sort.Ints(sorted)
    rank := make(map[int]int)
    r := 1
    for _, v := range sorted {
        if _, ok := rank[v]; !ok {
            rank[v] = r
            r++
        }
    }
    for i := 0; i < n; i++ {
        arr[i] = rank[arr[i]]
    }
    return arr
}
