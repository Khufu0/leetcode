import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;

public class courseSchedule207 {
    static class Solution {
        public Boolean dfs(HashMap<Integer, ArrayList<Integer>> adj, HashSet<Integer> visited,
                Integer current) {
            if (adj.get(current) == null) {
                return true;
            }
            if (visited.contains(current)) {
                return false;
            }
            visited.add(current);
            for (Integer integer : adj.get(current)) {
                if (!dfs(adj, visited, integer)) {
                    return false;
                }
            }
            visited.remove(current);
            adj.put(current, new ArrayList<Integer>());
            return true;
        }


        public boolean canFinish(int numCourses, int[][] prerequisites) {
            if (prerequisites.length == 0)
                return true;

            HashMap<Integer, ArrayList<Integer>> adj = new HashMap<>(numCourses);
            for (int i = 0; i < prerequisites.length; i++) {
                int from = prerequisites[i][0];
                int to = prerequisites[i][1];
                if (from == to) {
                    return false;
                }
                if (adj.get(from) == null) {
                    adj.put(from, new ArrayList<Integer>());
                }
                adj.get(from).add(to);
            }

            HashSet<Integer> visited = new HashSet<>(numCourses);
            for (Integer integer : adj.keySet()) {
                if (!dfs(adj, visited, integer)) {
                    return false;
                }
            }
            return true;
        }
    }

    public static void main(String[] args) {
        int[][] p = {{0, 1}, {0, 2}, {1, 2}};
        Solution s = new Solution();
        System.out.println(s.canFinish(3, p));

        int[][] p2 = {{0, 1}, {0, 2}, {1, 0}};
        System.out.println(s.canFinish(3, p2));
    }
}
