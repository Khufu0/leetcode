/**
 * @param {number} n
 * @return {number}
 */
var numTilings = function (n) {
    switch (n) {
        case 1:
        case 2:
            return n;
        case 3:
            return 5;
        default:
            let prev = 5; // n = 3
            let prevprev = 2; // n = 2
            let prevprevprev = 1; // n = 1
            for (let i = 4; i <= n; i++) {
                let temp = (2 * prev + prevprevprev) % (Math.pow(10, 9) + 7);
                prevprevprev = prevprev;
                prevprev = prev;
                prev = temp;
            }
            return prev;
    }
};
