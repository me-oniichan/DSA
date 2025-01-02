func vowelStrings(words []string, queries [][]int) []int {
    prefix := make([]int, len(words)+1)
    wcount := 0
    for i, word := range words {
        begvow, endvow := false, false
        switch word[0] {
            case 'a', 'e', 'i', 'o', 'u': begvow = true
        }
        switch word[len(word)-1] {
            case 'a', 'e', 'i', 'o', 'u': endvow = true
        }
        if begvow && endvow {
            wcount++
        }
        prefix[i+1] = wcount
    }
    res := make([]int, len(queries))
    for i, query := range queries {
        l,r := query[0], query[1]
        res[i] = prefix[r+1] - prefix[l]
    }
    return res
}
