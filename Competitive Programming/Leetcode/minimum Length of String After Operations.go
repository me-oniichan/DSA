func minimumLength(s string) int {
    charCount := make([]int, 26)
    for _, c := range s {
        charCount[c - 'a']++
    }
    res := 0
    for _, c := range charCount {
        if c == 0 {
            continue
        }
        if c % 2 == 1 {
            res++
        } else{
            res+=2
        }
    }
    return res
}
