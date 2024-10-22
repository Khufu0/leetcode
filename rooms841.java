import java.util.LinkedHashSet;
import java.util.List;
import java.util.Set;
import java.util.Stack;

public class rooms841 {
    class Solution {
        public boolean canVisitAllRooms(List<List<Integer>> rooms) {
            Set<Integer> visited = new LinkedHashSet<>();
            Stack<Integer> stack = new Stack<>();
            stack.push(0);
            while (!stack.empty()) {
                int node = stack.pop();
                visited.add(node);
                for (Integer n : rooms.get(node)) {
                    if (!visited.contains(n))
                        stack.push(n);
                }
            }
            return visited.size() == rooms.size();
        }
    }
}