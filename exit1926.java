import java.util.LinkedList;
import java.util.Queue;

public class exit1926 {
    static class Solution {
        public int nearestExit(char[][] maze, int[] entrance) {
            int rows = maze.length;
            int cols = maze[0].length;
            Queue<int[]> q = new LinkedList<>();
            q.add(new int[] {entrance[0], entrance[1], 0});
            while (!q.isEmpty()) {
                int[] curr = q.poll();
                int x = curr[0];
                int y = curr[1];
                int w = curr[2];

                if (x < 0 || y < 0 || x >= rows || y >= cols || maze[x][y] == '+') {
                    continue;
                }
                if (edge(rows, cols, curr, entrance)) {
                    return w;
                }

                q.add(new int[] {x - 1, y, w + 1});
                q.add(new int[] {x, y - 1, w + 1});
                q.add(new int[] {x + 1, y, w + 1});
                q.add(new int[] {x, y + 1, w + 1});
                maze[x][y] = '+';
            }
            return -1;
        }

        boolean edge(int rows, int cols, int[] point, int[] entrance) {
            int x = point[0];
            int y = point[1];
            if ((x != entrance[0] || y != entrance[1])
                    && (x == rows - 1 || y == cols - 1 || x == 0 || y == 0)) {
                return true;
            }
            return false;
        }
    }

    public static void main(String[] args) {
        Solution s = new Solution();
        char[][] maze = {{'+', '+', '.', '+'}, {'.', '.', '.', '+'}, {'+', '+', '+', '.'}};
        int[] entrance = {1, 2};
        System.out.println(s.nearestExit(maze, entrance));
    }
}
