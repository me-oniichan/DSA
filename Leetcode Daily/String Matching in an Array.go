func stringMatching(words []string) []string {
    res := []string{}
    for i, word := range words {
        for j, other := range words {
            if i != j && strings.Contains(other, word) {
                res = append(res, word)
                break
            }
        }
    }
    return res
}
