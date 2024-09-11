func minBitFlips(start, goal int) int{
    bits:= start^goal
    count:=0
    for i:=0;i<32;i++{
        if bits&1==1{
            count++
        }
        bits>>=1
    }
    return count
}
