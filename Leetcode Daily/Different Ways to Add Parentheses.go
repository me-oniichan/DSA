func diffWaysToCompute(expression string) []int {
    if len(expression) == 0 {
        return []int{}
    }
    res := []int{}
    for i := 0; i < len(expression); i++ {
        if expression[i] == '+' || expression[i] == '-' || expression[i] == '*' {
            left := diffWaysToCompute(expression[:i])
            right := diffWaysToCompute(expression[i+1:])
            for _, l := range left {
                for _, r := range right {
                    if expression[i] == '+' {
                        res = append(res, l + r)
                    } else if expression[i] == '-' {
                        res = append(res, l - r)
                    } else {
                        res = append(res, l * r)
                    }
                }
            }
        }
    }
    if len(res) == 0 {
        num, _ := strconv.Atoi(expression)
        res = append(res, num)
    }
    return res
}
