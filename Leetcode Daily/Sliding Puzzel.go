func slidingPuzzle(board [][]int) int {
    target := [][]int{{1, 2, 3}, {4, 5, 0}}
    if reflect.DeepEqual(board, target) {
        return 0
    }
    visited := make(map[string]bool)
    queue := make([][][]int, 0)
    queue = append(queue, board)
    visited[boardToString(board)] = true
    step := 0
    for len(queue) > 0 {
        step++
        size := len(queue)
        for i := 0; i < size; i++ {
            cur := queue[0]
            queue = queue[1:]
            for _, next := range getNext(cur) {
                if reflect.DeepEqual(next, target) {
                    return step
                }
                if visited[boardToString(next)] {
                    continue
                }
                visited[boardToString(next)] = true
                queue = append(queue, next)
            }
        }
    }
    return -1
}

func getNext(board [][]int) [][][]int {
    next := make([][][]int, 0)
    x, y := 0, 0
    for i := 0; i < 2; i++ {
        for j := 0; j < 3; j++ {
            if board[i][j] == 0 {
                x, y = i, j
                break
            }
        }
    }
    for i := 0; i < 4; i++ {
        nx, ny := x+dx[i], y+dy[i]
        if nx < 0 || nx >= 2 || ny < 0 || ny >= 3 {
            continue
        }
        newBoard := make([][]int, 2)
        for i := 0; i < 2; i++ {
            newBoard[i] = make([]int, 3)
            copy(newBoard[i], board[i])
        }
        newBoard[x][y], newBoard[nx][ny] = newBoard[nx][ny], newBoard[x][y]
        next = append(next, newBoard)
    }
    return next
}

func boardToString(board [][]int) string {
    res := ""
    for i := 0; i < 2; i++ {
        for j := 0; j < 3; j++ {
            res += strconv.Itoa(board[i][j])
        }
    }
    return res
}

var dx = []int{0, 0, 1, -1}
var dy = []int{1, -1, 0, 0}
