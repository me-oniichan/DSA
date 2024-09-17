func uncommonFromSentences(s1, s2 string) []string {
    m := make(map[string]int)
    for _, v := range strings.Split(s1 + " " + s2, " ") {
        m[v]++
    }
    var res []string
    for k, v := range m {
        if v == 1 {
            res = append(res, k)
        }
    }
    return res
}
