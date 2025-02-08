type NumberContainers struct {
    indexToNumber map[int]int
    numberToIndex map[int][]int
}


func Constructor() NumberContainers {
    return NumberContainers{
        indexToNumber: make(map[int]int),
        numberToIndex: make(map[int][]int),
    } 
}


func (this *NumberContainers) Change(index int, number int)  {
    prevNumber, ok := this.indexToNumber[index]
    if ok {
        this.numberToIndex[prevNumber] = remove(this.numberToIndex[prevNumber], index)
    }
    this.indexToNumber[index] = number
    this.numberToIndex[number] = append(this.numberToIndex[number], index)
}


func (this *NumberContainers) Find(number int) int {
    if len(this.numberToIndex[number]) == 0 {
        return -1
    }
    return slices.Min(this.numberToIndex[number])
}

func remove(arr []int, target int) []int {
    for i, v := range arr {
        if v == target {
            return append(arr[:i], arr[i+1:]...)
        }
    }
    return arr
}
