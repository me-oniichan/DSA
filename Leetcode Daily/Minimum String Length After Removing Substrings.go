func minLength(s string) int {
    stack := []byte{}
    for i := 0; i < len(s); i++ {
        if len(stack) == 0 || stack[len(stack)-1] != 'A' && stack[len(stack)-1] != 'C'{
            stack = append(stack, s[i])
        } else if stack[len(stack)-1] == 'A' && s[i] == 'B'{
            stack = stack[:len(stack)-1]
        } else if stack[len(stack)-1] == 'C' && s[i] == 'D'{
            stack = stack[:len(stack)-1]
        } else {
            stack = append(stack, s[i])
        }
    }
    return len(stack)
}
