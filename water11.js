/**
 * @param {number[]} height
 * @return {number}
 */
var maxArea = function (height) {
	let max = -Infinity;
	let l = 0,
		r = height.length - 1;
	while (l != r) {
		const h1 = height[l];
		const h2 = height[r];
		const water = (r - l) * Math.min(h1, h2);
		if (water > max) max = water;
		if (h1 < h2) l++;
		else r--;
	}
	return max;
};

console.log(maxArea([1, 8, 6, 2, 5, 4, 8, 3, 7]) == 49);

// var maxArea = function (height) {
// 	let max = -Infinity;
// 	for (let i = 0; i < height.length; i++) {
// 		const h1 = height[i];

// 		for (let j = height.length - 1; j > i; j--) {
// 			const h2 = height[j];
// 			const water = (j - i) * Math.min(h1, h2);
// 			if (water > max) max = water;
// 		}
// 	}
// 	return max;
// };
