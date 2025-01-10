func countPrefixSuffixPairs(words []string) int {
    n := len(words)
    res := 0
    for i := 0; i < n; i++ {
        for j := i+1; j < n; j++ {
            if strings.HasPrefix(words[j], words[i]) && strings.HasSuffix(words[j], words[i]){
                res++
            }
        }
    }
    return res
}
