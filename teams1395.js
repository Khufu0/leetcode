/**
 * @param {number[]} rating
 * @return {number}
 */
var numTeams = function (rating) {
    let n = rating.length;
    let res = 0;
    for (let m = 1; m < n - 1; m++) {
        let ls = 0,
            rg = 0;
        for (let i = 0; i < m; i++) {
            if (rating[i] < rating[m]) ls++;
        }
        for (let i = m + 1; i < n; i++) {
            if (rating[i] > rating[m]) rg++;
        }
        let lg = m - ls,
            rs = n - m - 1 - rg;
        res += ls * rg + lg * rs;
    }
    return res;
};

console.log(numTeams([2, 5, 3, 4, 1]));

/*
var numTeams = function (rating) {
    let n = rating.length;
    let memol = new Map();
    let memog = new Map();
    for (let i = 0; i < n; i++) {
        memol[i] = 0;
        memog[i] = 0;
    }

    for (let i = 0; i < n; i++) {
        for (let j = i + 1; j < n; j++) {
            if (rating[i] < rating[j]) memol[i]++;
            if (rating[i] > rating[j]) memog[i]++;
        }
    }

    let res = 0;
    for (let i = 0; i < n; i++) {
        for (let j = i + 1; j < n; j++) {
            if (rating[i] < rating[j]) res += memol[j];
            if (rating[i] > rating[j]) res += memog[j];
        }
    }
    return res;
};
*/
