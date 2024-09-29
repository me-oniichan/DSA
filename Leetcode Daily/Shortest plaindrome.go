func shortestPalindrome(s string) string {
    if s==""{
        return ""
    }

    s = s+" "+reverse(s)
    n := len(s)
    lps := make([]int, n)
    for i:=1; i<n; i++{
        j := lps[i-1]
        for j>0 && s[i]!=s[j]{
            j = lps[j-1]
        }
        if s[i]==s[j]{
            j++
        }
        lps[i] = j
    }
    fmt.Println(s)
    fmt.Println(lps)
    return s[n/2+1:n-lps[n-1]]+s[:n/2]

}

func reverse(s string) string{
    n := len(s)
    b := []byte(s)
    for i:=0; i<n/2; i++{
        b[i], b[n-1-i] = b[n-1-i], b[i]
    }
    return string(b)
}
