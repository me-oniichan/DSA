func findTheLongestSubstring(s string) int {
    vowels := "aeiou"
    count := make(map[int]int)
    count[0] = -1
    res := 0
    state := 0
    for i := 0; i < len(s); i++ {
        for j := 0; j < len(vowels); j++ {
            if s[i] == vowels[j] {
                state ^= 1 << j
            }
        }
        if _, ok := count[state]; !ok {
            count[state] = i
        }
        res = max(res, i - count[state])
    }
    return res
}
