func prefixCount(words []string, pref string) int {
    res := 0
    for _, word := range words {
        if strings.HasPrefix(word, pref) {
            res++
        }
    }
    return res
}
