type MyCalendarTwo struct {
    firstbook []int
    secondbook []int
}


func Constructor() MyCalendarTwo {
    return MyCalendarTwo{firstbook: []int{}, secondbook: []int{}}
}


func (this *MyCalendarTwo) Book(start int, end int) bool {
    for i:=0; i < len(this.secondbook); i+=2 {
        if start < this.secondbook[i+1] && end > this.secondbook[i] {
            return false
        }
    }
    for i:=0; i < len(this.firstbook); i+=2 {
        if start < this.firstbook[i+1] && end > this.firstbook[i] {
            this.secondbook = append(this.secondbook, max(this.firstbook[i], start), min(this.firstbook[i+1], end))
        }
    }
    this.firstbook = append(this.firstbook, start, end)
    return true
}
