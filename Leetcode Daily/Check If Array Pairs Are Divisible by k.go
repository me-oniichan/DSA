func canArrange(arr []int, k int) bool {
    m := make(map[int]int)
    for _, v := range arr {
        m[(v%k+k)%k]++
    }
    for i := 1; i < k; i++ {
        if m[i] != m[k-i] {
            return false
        }
    }
    return m[0]%2 == 0
}
