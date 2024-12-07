/**
 * @param {number[][]} matrix
 * @return {number}
 */
var maxMatrixSum = function (matrix) {
    let absSum = 0;
    let negativeCount = 0;
    let minAbs = Infinity;
    for (const row of matrix) {
        for (const val of row) {
            let absVal = Math.abs(val);
            absSum += absVal;
            minAbs = Math.min(minAbs, absVal);
            if (val < 0) negativeCount++;
        }
    }
    return negativeCount & 1 ? absSum - 2 * minAbs : absSum;
};
