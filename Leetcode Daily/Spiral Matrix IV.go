package main
type ListNode struct {
    Val int
    Next *ListNode
}

func spiralMatrix(m int, n int, head *ListNode) [][]int {
    res := make([][]int, m)
    for i := range res {
        res[i] = make([]int, n)
    }
    
    for i := range res {
        for j := range res[i] {
            res[i][j] = -1
        }
    }

    cur := head
    
    x, y := 0, 0
    d := 0
    for cur != nil {
        res[x][y] = cur.Val
        cur = cur.Next
        switch d {
        case 0:
            if y == n - 1 || res[x][y + 1] != -1 {
                d = 1
                x++
            } else {
                y++
            }
        case 1:
            if x == m - 1 || res[x + 1][y] != -1 {
                d = 2
                y--
            } else {
                x++
            }
        case 2:
            if y == 0 || res[x][y - 1] != -1 {
                d = 3
                x--
            } else {
                y--
            }
        case 3:
            if x == 0 || res[x - 1][y] != -1 {
                d = 0
                y++
            } else {
                x--
            }
        }
    }

    return res
}
