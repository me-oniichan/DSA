type MyCalendar struct {
    days []int
}


func Constructor() MyCalendar {
    return MyCalendar{
        days: make([]int, 0)
    }
}


func (this *MyCalendar) Book(start int, end int) bool {
    for i := 0; i < len(this.days); i += 2 {
        if start < this.days[i+1] && end > this.days[i] {
            return false
        }
    }
    this.days = append(this.days, start, end)
    return true 
}
