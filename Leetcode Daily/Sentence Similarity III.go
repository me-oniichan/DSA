func areSentencesSimilar(sentence1 string, sentence2 string) bool {
    s1 := strings.Split(sentence1, " ")
    s2 := strings.Split(sentence2, " ")
    if len(s1) == len(s2) {
        return reflect.DeepEqual(s1, s2)
    }
    if len(s1) > len(s2) {
        s1, s2 = s2, s1
    }
    
    prefix := -1
    suffix := len(s1)

    for i := 0; i < len(s1); i++ {
        if s1[i] == s2[i] {
            prefix++
        } else {
            break
        }
    }

    for i := 0; i < len(s1); i++ {
        if s1[len(s1)-1-i] == s2[len(s2)-1-i] {
            suffix = len(s1)-1-i
        }else {
            break
        }
    }

    if prefix+1 >= suffix {
        return true
    }
    return false
}
