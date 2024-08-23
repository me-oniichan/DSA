func fractionAddition(expression string) string {
    fraction, idx := make(map[int]int), 0
    for idx < len(expression) {
        top, down := "", ""
        for expression[idx] != '/' {
            top += string(expression[idx])
            idx += 1
        }
        idx += 1
        for idx < len(expression) && expression[idx] != '+' && expression[idx] != '-' {
            down += string(expression[idx])
            idx += 1
        }
        t, _ := strconv.Atoi(top)
        d, _ := strconv.Atoi(down)
        fraction[d] += t
    }
    downs := make([]int, 0)
    for k, v := range fraction {
        if v == 0 {
            continue
        }
        downs = append(downs, k)
    }
    if len(downs) == 0 {
        return "0/1"
    }
    gcd := func(a, b int) int {
        for b > 0 {
            t := a % b
            a, b = b, t
        }
        return a
    }
    if len(downs) == 1 {
        g := gcd(int(math.Abs(float64(fraction[downs[0]]))), downs[0])
        return fmt.Sprintf("%v/%v", fraction[downs[0]] / g, downs[0] / g)
    }
    top, down := 0, 1
    for _, val := range downs {
        top, down = (top * val + fraction[val] * down), down * val
        g := gcd(int(math.Abs(float64(top))), down)
        top, down = top / g, down / g
    }
    return fmt.Sprintf("%v/%v", top, down)
}
