func maxEqualRowsAfterFlips(matrix [][]int) int {
    m := make(map[string]int)
    for _, row := range matrix {
        s1, s2 := "", ""
        for _, v := range row {
            s1 += strconv.Itoa(v)
            s2 += strconv.Itoa(1-v)
        }
        m[s1]++
        m[s2]++
    }
    res := 0
    for _, v := range m {
        res = max(res, v)
    }
    return res
}
