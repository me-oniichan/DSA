func numberOfSubstrings(s string) int {
    n := len(s)
    cnt := [3]int{}
    res := 0
    for l, r := 0, 0; r < n; r++ {
        cnt[s[r]-'a']++
        for cnt[0] > 0 && cnt[1] > 0 && cnt[2] > 0 {
            res += n - r
            cnt[s[l]-'a']--
            l++
        }
    }
    return res
}
