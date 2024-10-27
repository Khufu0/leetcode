import java.util.PriorityQueue;

public class kWorkers2462 {
    class Solution {
        public long totalCost(int[] costs, int k, int candidates) {
            PriorityQueue<Integer> pql = new PriorityQueue<>(candidates);
            PriorityQueue<Integer> pqr = new PriorityQueue<>(candidates);
            int l = 0;
            int r = costs.length - 1;
            while (l < candidates) {
                pql.add(costs[l++]);
                if (r >= Math.max(candidates, costs.length - candidates)) {
                    pqr.add(costs[r--]);
                }
            }

            long cost = 0;
            while (k-- != 0) {
                if (pqr.isEmpty() || !pql.isEmpty() && pql.peek() <= pqr.peek()) {
                    cost += pql.poll();
                    if (l <= r) {
                        pql.add(costs[l++]);
                    }
                } else {
                    cost += pqr.poll();
                    if (l <= r) {
                        pqr.add(costs[r--]);
                    }
                }
            }
            return cost;
        }
    }
}
