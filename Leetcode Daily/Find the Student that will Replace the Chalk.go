func chalkReplacer(chalk []int, k int) int {
    sum := 0
    for _, v := range chalk {
        sum += v
    }
    k %= sum
    for i, v := range chalk {
        if k < v {
            return i
        }
        k -= v
    }
    return -1
}
