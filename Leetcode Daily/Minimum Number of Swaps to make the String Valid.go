func minAddToMakeValid(s string) int {
    stack := make([]byte, 0)
    inserts := 0
    for i := 0; i < len(s); i++ {
        if s[i] == '(' {
            stack = append(stack, s[i])
        } else s[i] == ')' {
            if len(stack) == 0 {
                inserts++
            } else {
                stack = stack[:len(stack)-1]
            }
        }
    }
    return inserts + len(stack)
}
