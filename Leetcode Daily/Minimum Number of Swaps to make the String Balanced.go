func minSwaps(s string) int {
    swaps := 0
    clsoing := 0
    opening := 0
    for i := 0; i < len(s); i++ {
        if s[i] == '['{
            opening++
        } else {
            clsoing++
        }

        if clsoing > opening {
            swaps++
            clsoing--
            opening++
        }
    }
    return swaps
}
