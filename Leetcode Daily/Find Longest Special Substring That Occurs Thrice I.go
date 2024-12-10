func maximumLength(s string) int {
    freqCount := make(map[string]int, 0)
    for l,r := 0,0; r < len(s); r++ {
        if r == len(s) - 1 || s[r] != s[r+1] {
            groupCount := r-l+1
            for ;l < r+1; l++ {
                freqCount[s[l:r+1]] += groupCount - (r-l)
            }
            l = r+1
        }
    }
    maxLen := -1
    for k,v := range freqCount {
        if v >= 3 && len(k) > maxLen {
            maxLen = len(k)
        }
    }
    return maxLen
}
