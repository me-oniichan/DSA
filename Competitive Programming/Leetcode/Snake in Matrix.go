func finalPositionOfSnake(n int, commands []string) int {
    x, y := 0, 0
    for _, c := range commands {
        if c == "LEFT" {
            x--
        } else if c == "RIGHT" {
            x++
        } else if c == "UP" {
            y--
        } else if c == "DOWN" {
            y++
        }
    }
    return n*y + x
}
