func minimizeXor(num1 int, num2 int) int {
    numbits := 0
    for; num2 > 0; num2 >>= 1 {
        if num2 & 1 == 1 {
            numbits++
        }
    }
    res := 0
    for i:=31; i >= 0 && numbits >0; i--{
        // res <<= 1
        if (num1 >> i) & 1 == 1{
            res |= 1 << i
            numbits--
        }
    }

    for ; numbits > 0; numbits--{
        for i:=0; i < 31; i++{
            if (res >> i) & 1 == 0{
                res |= 1 << i
                break
            }
        }
    }
    return res
}
