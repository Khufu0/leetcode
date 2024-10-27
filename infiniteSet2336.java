import java.util.PriorityQueue;

public class infiniteSet2336 {
    class SmallestInfiniteSet {
        private int curr = 1;
        private PriorityQueue<Integer> back = new PriorityQueue<>();

        public SmallestInfiniteSet() {

        }

        public int popSmallest() {
            if (!back.isEmpty())
                return back.poll();
            return curr++;
        }

        public void addBack(int num) {
            if (num < curr && !back.contains(num))
                back.add(num);
        }
    }
}