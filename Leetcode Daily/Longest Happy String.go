type Pair struct {
    c byte
    cnt int
}

func longestDiverseString(a int, b int, c int) string {
    var res []byte
    cnta, cntb, cntc := 0, 0, 0
    for _ = range a+b+c {
        p1 := top(a, b, c)
        if p1 == 'a' && cnta < 2 || (a > 0 && (cntb ==2 || cntc == 2)) {
            res = append(res, 'a')
            a--
            cnta++
            cntb, cntc = 0, 0
        } else if p1 == 'b' && cntb < 2 || (b> 0 && (cnta == 2 || cntc == 2)) {
            res = append(res, 'b')
            b--
            cntb++
            cnta, cntc = 0, 0
        } else if p1 == 'c' && cntc < 2 || (c > 0 && (cnta == 2 || cntb == 2)) {
            res = append(res, 'c')
            c--
            cntc++
            cnta, cntb = 0, 0
        }
    }
    return string(res)
}

func top(a, b, c int) byte {
    if a >= b && a >= c {
        return 'a'
    } else if b >= a && b >= c {
        return 'b'
    } else {
        return 'c'
    }
}
