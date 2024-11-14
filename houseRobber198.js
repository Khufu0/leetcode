/**
 * @param {number[]} nums
 * @return {number}
 */
var rob = function (nums) {
    let memo = {};
    let recurse = function (i) {
        if (i >= nums.length) return 0;
        if (memo[i] !== undefined) return memo[i];
        memo[i] = Math.max(recurse(i + 1), recurse(i + 2) + nums[i]);
        return memo[i];
    };
    return recurse(0);
};

console.log(rob([1, 2, 3, 1]));
console.log(rob([2, 7, 9, 3, 1]));
console.log(
    rob([
        104, 209, 137, 52, 158, 67, 213, 86, 141, 110, 151, 127, 238, 147, 169,
        138, 240, 185, 246, 225, 147, 203, 83, 83, 131, 227, 54, 78, 165, 180,
        214, 151, 111, 161, 233, 147, 124, 143,
    ])
);
