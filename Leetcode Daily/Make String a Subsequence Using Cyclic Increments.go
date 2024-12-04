func canMakeSubsequence(str1 string, str2 string) bool {
    str2ptr := 0
    for i := 0; i < len(str1); i++ {
        if str1[i] == str2[str2ptr] || (str1[i]-'a'+1)%26 == (str2[str2ptr]-'a') {
            str2ptr++
            if str2ptr == len(str2) {
                return true
            }
        }
    }
}
