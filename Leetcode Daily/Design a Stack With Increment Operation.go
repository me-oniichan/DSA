type CustomStack struct {
    stack []int
    maxSize int
}


func Constructor(maxSize int) CustomStack {
    return CustomStack{maxSize: maxSize}
}


func (this *CustomStack) Push(x int)  {
    if len(this.stack) < this.maxSize {
        this.stack = append(this.stack, x)
    }
}


func (this *CustomStack) Pop() int {
    if len(this.stack) == 0 {
        return -1
    }
    res := this.stack[len(this.stack)-1]
    this.stack = this.stack[:len(this.stack)-1]
    return res
}


func (this *CustomStack) Increment(k int, val int)  {
    for i := 0; i < k && i < len(this.stack); i++ {
        this.stack[i] += val
    }
}
