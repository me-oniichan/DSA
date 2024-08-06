func minimumPushes(word string) int {
    keyfreq := make([]int, 26)
    for _, c := range word {
        keyfreq[c-'a']++
    }
    
    sort.Sort(sort.Reverse(sort.IntSlice(keyfreq)))
    
    ans := 0
    accumulator := func(slice []int) int {
        sum := 0
        for _, v := range slice {
            sum += v
        }
        return sum
    }

    ans = accumulator(keyfreq[0:8])
    ans += accumulator(keyfreq[8:16])*2
    ans += accumulator(keyfreq[16:24])*3
    ans += accumulator(keyfreq[24:26])*4
    
    return ans;
}
