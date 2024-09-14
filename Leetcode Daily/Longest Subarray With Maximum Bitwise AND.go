func longestSubarray(num []int) int{
    maxlen := 0
    count := 0
    maxnum := slices.Max(num)
    for i := 0; i < len(num); i++ {
        if num[i] == maxnum {
            count++
            maxlen = max(maxlen, count)
        } else {
            count = 0
        }
    }
    return maxlen
}
