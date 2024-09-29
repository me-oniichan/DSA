type AllOne struct {
    wordmap map[string]int
    freqmap map[int]map[string]bool
    freqlist []int
}


func Constructor() AllOne {
    return AllOne{
        wordmap: make(map[string]int),
        freqmap: make(map[int]map[string]bool),
        freqlist: []int{},
    }
}


func (this *AllOne) Inc(key string)  {
    if _, ok := this.wordmap[key]; !ok {
        this.wordmap[key] = 1
        if _, ok := this.freqmap[1]; !ok {
            this.freqmap[1] = make(map[string]bool)
        }
        this.freqmap[1][key] = true
        if len(this.freqlist) == 0 || this.freqlist[0] != 1 {
            this.freqlist = append([]int{1}, this.freqlist...)
        }
        
    } else {
        this.wordmap[key]++
        delete(this.freqmap[this.wordmap[key]-1], key)
        if len(this.freqmap[this.wordmap[key]-1]) == 0 {
            delete(this.freqmap, this.wordmap[key]-1)
            for i, v := range this.freqlist {
                if v == this.wordmap[key]-1 {
                    this.freqlist = append(this.freqlist[:i], this.freqlist[i+1:]...)
                    break
                }
            }
        }
        if _, ok := this.freqmap[this.wordmap[key]]; !ok {
            this.freqmap[this.wordmap[key]] = make(map[string]bool)
            this.freqlist = append(this.freqlist, this.wordmap[key])
            sort.Ints(this.freqlist)
        }
        this.freqmap[this.wordmap[key]][key] = true
    } 
}


func (this *AllOne) Dec(key string)  {
    if _, ok := this.wordmap[key]; !ok {
        return
    }
    this.wordmap[key]--
    delete(this.freqmap[this.wordmap[key]+1], key)
    if len(this.freqmap[this.wordmap[key]+1]) == 0 {
        delete(this.freqmap, this.wordmap[key]+1)
        for i, v := range this.freqlist {
            if v == this.wordmap[key]+1 {
                this.freqlist = append(this.freqlist[:i], this.freqlist[i+1:]...)
                break
            }
        }
    }
    if this.wordmap[key] == 0 {
        delete(this.wordmap, key)
    } else {
        if _, ok := this.freqmap[this.wordmap[key]]; !ok {
            this.freqmap[this.wordmap[key]] = make(map[string]bool)
            this.freqlist = append(this.freqlist, this.wordmap[key])
            sort.Ints(this.freqlist)
        }
        this.freqmap[this.wordmap[key]][key] = true
    } 
}

func (this *AllOne) GetMaxKey() string {
    if len(this.freqlist) == 0{
        return ""
    }
    for key, _ := range this.freqmap[this.freqlist[len(this.freqlist)-1]] {
        return key
    }
    return ""
}


func (this *AllOne) GetMinKey() string {
    if len(this.freqlist) == 0{
        return ""
    }
    for key, _ := range this.freqmap[this.freqlist[0]] {
        return key
    }
    return ""
}
