func countConsistentStrings(allowed string, words []string) int {
    allowedMap := make(map[byte]bool)
    for i := 0; i < len(allowed); i++ {
        allowedMap[allowed[i]] = true
    }
    res := 0
    for i := 0; i < len(words); i++ {
        flag := true
        for j := 0; j < len(words[i]); j++ {
            if _, ok := allowedMap[words[i][j]]; !ok {
                flag = false
                break
            }
        }
        if flag {
            res++
        }
    }
    return res
}
