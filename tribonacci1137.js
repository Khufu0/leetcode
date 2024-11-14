/**
 * @param {number} n
 * @return {number}
 */
var tribonacci = function (n) {
    let memo = { 0: 0, 1: 1, 2: 1 };
    let calc = (x) => {
        if (memo[x] !== undefined) return memo[x];
        memo[x] = calc(x - 1) + calc(x - 2) + calc(x - 3);
        return memo[x];
    };
    return calc(n);
};
