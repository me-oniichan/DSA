func finalPrices(prices []int) []int {
    mstack := make([]int,0)

    for i:=len(prices)-1;i>=0;i--{
        for len(mstack) > 0 && prices[i] < mstack[len(mstack)-1]{
            mstack = mstack[:len(mstack)-1]
        }
        elem:=prices[i]
        if len(mstack) > 0{
            prices[i] -= mstack[len(mstack)-1]
        }
        mstack = append(mstack,elem)
    }
    return prices
}
