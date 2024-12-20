import { MinPriorityQueue } from "datastructures-js";

/**
 * @param {number[][]} points
 * @return {number}
 */
var minCostConnectPoints = function (points) {
    let n = points.length;
    let visited = new Set();
    let unvisited = new Set();
    // Initialize unvisited set with values from 0 to n-1
    for (let i = 0; i < n; i++) {
        unvisited.add(i);
    }
    let cost = 0;
    // priority queue that will store the point and cost
    // and ranks them based on the cost
    let pq = new MinPriorityQueue((x) => x[1]);
    pq.enqueue([0, 0]); // idx, cost
    while (!pq.isEmpty()) {
        let [idx, weight] = pq.dequeue();
        let point = points[idx];

        if (visited.has(idx)) continue;
        visited.add(idx);
        unvisited.delete(idx);
        cost += weight;
        if (visited.size === n) break;

        unvisited.forEach((i) => {
            pq.enqueue([i, manhattanDistance(point, points[i])]);
        });
    }
    return cost;
};

/**
 * @param {number[]} a
 * @param {number[]} b
 * @return {number}
 */
function manhattanDistance(a, b) {
    return Math.abs(a[0] - b[0]) + Math.abs(a[1] - b[1]);
}

console.log(
    minCostConnectPoints([
        [0, 0],
        [2, 2],
        [3, 10],
        [5, 2],
        [7, 0],
    ]) == 20
);
