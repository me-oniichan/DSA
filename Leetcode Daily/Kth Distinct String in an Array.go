func kthDistinct(arr []string, k int) string {
    m := make(map[string]int)
    for _, v := range arr {
        m[v]++
    }
    for _, v := range arr {
        if m[v] == 1 {
            k--
        }
        if k == 0 {
            return v
        }
    }
    return ""
}
