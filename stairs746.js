/**
 * @param {number[]} cost
 * @return {number}
 */
var minCostClimbingStairs = function (cost) {
    let memo = {};
    let recurse = function (i) {
        if (i >= cost.length) return 0;
        if (memo[i] !== undefined) return memo[i];
        memo[i] = Math.min(recurse(i + 1), recurse(i + 2)) + cost[i];
        return memo[i];
    };
    return Math.min(recurse(0), recurse(1));
};

let a = [10, 15, 20];
console.log(minCostClimbingStairs(a));
