type ProductOfNumbers struct {
    nums []int
}


func Constructor() ProductOfNumbers {
    return ProductOfNumbers{
        nums: []int{},
    }
}


func (this *ProductOfNumbers) Add(num int)  {
    if num == 0{
        this.nums = make([]int,0)
    }else if len(this.nums) == 0 {
        this.nums = append(this.nums, num)
    } else {
        this.nums = append(this.nums, this.nums[len(this.nums)-1]*num)
    }
}


func (this *ProductOfNumbers) GetProduct(k int) int {
    if k > len(this.nums){
        return 0
    }else if k == len(this.nums){
        return this.nums[len(this.nums)-1]
    }

    return this.nums[len(this.nums)-1]/this.nums[len(this.nums)-k-1]
}


/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Add(num);
 * param_2 := obj.GetProduct(k);
 */
