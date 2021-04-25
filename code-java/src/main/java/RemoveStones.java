import java.util.ArrayDeque;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Objects;
import java.util.Queue;
import java.util.Set;
import java.util.Stack;

/**
 * On a 2D plane, we place stones at some integer coordinate points.  Each coordinate point may have at most one stone.
 * <p>
 * Now, a move consists of removing a stone that shares a column or row with another stone on the grid.
 * <p>
 * What is the largest possible number of moves we can make?
 * <p>
 * <a href="https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/>
 */
public class RemoveStones {

    private final Set<Stone> visitedStones = new HashSet<>();
    private final Map<Stone, Integer> stoneGroupMemberCount = new HashMap<>();
    private final Queue<Stone> stoneQueue = new ArrayDeque<>(NUM_ROW + 1);

    private static final int NUM_ROW = 1005;
    private static final int NUM_COL = 10005;

    private final int[][] stoneMatrix = new int[NUM_ROW][NUM_COL];

    public int removeStones(int[][] stones) {
        int N = stones.length;

        // graph[i][0] = the length of the 'list' graph[i][1:]
        int[][] graph = new int[N][N];
        for (int i = 0; i < N; ++i)
            for (int j = i + 1; j < N; ++j)
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    graph[i][++graph[i][0]] = j;
                    graph[j][++graph[j][0]] = i;
                }

        int ans = 0;
        boolean[] seen = new boolean[N];
        for (int i = 0; i < N; ++i)
            if (!seen[i]) {
                Stack<Integer> stack = new Stack();
                stack.push(i);
                seen[i] = true;
                ans--;
                while (!stack.isEmpty()) {
                    int node = stack.pop();
                    ans++;
                    for (int k = 1; k <= graph[node][0]; ++k) {
                        int nei = graph[node][k];
                        if (!seen[nei]) {
                            stack.push(nei);
                            seen[nei] = true;
                        }
                    }
                }
            }

        return ans;
    }

    private static class Stone {

        private final int row;
        private final int col;
        private Stone parent;

        Stone(int row, int col, Stone parent) {
            this.row = row;
            this.col = col;
            this.parent = parent;
        }

        @Override
        public String toString() {
            return "(" + row + "," + col + ")";
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            Stone pair = (Stone) o;
            return row == pair.row &&
                    col == pair.col;
        }

        @Override
        public int hashCode() {
            return Objects.hash(row, col);
        }
    }

//     public static void main(String[] args) {
//         int[][] stonesA = {{0, 0}, {0, 1}, {1, 0}, {1, 2}, {2, 1}, {2, 2}};
//         int[][] stonesB = {{0, 0}, {0, 2}, {1, 1}, {2, 0}, {2, 2}};
//         int[][] stonesC = {{0, 0}};
//         int[][] stonesD = {{0, 1}, {1, 1}};
//         int[][] stonesE = {{0, 0}, {0, 1}, {1, 0}, {1, 1}, {2, 1}, {2, 2}, {3, 2}, {3, 3}, {3, 4}, {4, 3}, {4, 4}};
//         int[][] stonesF = {{3, 2}, {3, 1}, {4, 4}, {1, 1}, {0, 2}, {4, 0}};
//         int[][] stonesG = {{0, 0}, {0, 2}, {1, 1}, {2, 0}, {2, 2}};


//         Solution obj = new Solution();

//         System.out.println(obj.removeStones(stonesF));
//     }
}
