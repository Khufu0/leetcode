/**
 * @param {number} n
 * @param {number} k
 * @return {number[][]}
 */
var combine = function (n, k) {
    let res = [];
    let comb = [];
    let recurse = (i) => {
        if (comb.length == k) {
            res.push([...comb]);
            return;
        }
        for (let j = i; j <= n; j++) {
            comb.push(j);
            recurse(j + 1);
            comb.pop();
        }
    };
    recurse(1);
    return res;
};
