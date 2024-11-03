import java.util.Stack;

public class stockSpan901 {
    static class StockSpanner {
        record Data(int span, int price) {
        }

        private Stack<Data> stack;

        public StockSpanner() {
            stack = new Stack<>();
        }

        public int next(int price) {
            int span = 1;
            while (!stack.isEmpty() && stack.peek().price <= price) {
                Data d = stack.pop();
                span += d.span;
            }
            stack.push(new Data(span, price));
            return span;
        }
    }

    public static void main(String[] args) {
        StockSpanner stockSpanner = new StockSpanner();
        stockSpanner.next(100); // return 1
        stockSpanner.next(80); // return 1
        stockSpanner.next(60); // return 1
        stockSpanner.next(70); // return 2
        stockSpanner.next(60); // return 1
        stockSpanner.next(75); // return 4, because the last 4 prices (including today's price of
                               // 75) were less than or equal to today's price.
        stockSpanner.next(85); // return 6
    }
}
