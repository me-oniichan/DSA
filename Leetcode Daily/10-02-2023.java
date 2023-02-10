import java.util.ArrayDeque;
import java.util.Queue;

class Solution {
    public int maxDistance(int[][] grid) {
        int dist = -1, size = grid.length;
        Queue<int[]> q = new ArrayDeque<int[]>();
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (grid[i][j] == 1)
                    q.add(new int[] { i, j });
            }
        }
        if(q.size()==size*size) return -1;
        while (!q.isEmpty()) {
            Queue<int[]> q2 = new ArrayDeque<int[]>();
            while (!q.isEmpty()) {
                int[] cords = q.poll();
                if (cords[0] != 0 &&  grid[cords[0] - 1][cords[1]]==0) {
                    grid[cords[0] - 1][cords[1]] = 1;
                    q2.add(new int[] { cords[0] - 1, cords[1] });
                }
                if (cords[0] != size - 1&&  grid[cords[0] + 1][cords[1]]==0) {
                    grid[cords[0] + 1][cords[1]] = 1;
                    q2.add(new int[] { cords[0] + 1, cords[1] });
                }
                if (cords[1] != size - 1&&  grid[cords[0]][cords[1]+1]==0) {
                    grid[cords[0]][cords[1] + 1] = 1;
                    q2.add(new int[] { cords[0], cords[1] + 1 });
                }
                if (cords[1] != 0&&  grid[cords[0]][cords[1]-1]==0) {
                    grid[cords[0]][cords[1] - 1] = 1;
                    q2.add(new int[] { cords[0], cords[1] - 1 });
                }
            }
            q=q2;
            dist++;
        }

        return dist;
    }
}