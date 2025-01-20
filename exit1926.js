/**
 * @param {character[][]} maze
 * @param {number[]} entrance
 * @return {number}
 */
var nearestExit = function (maze, entrance) {
    let rows = maze.length;
    let cols = maze[0].length;
    let q = [[...entrance, 0]];
    while (q.length != 0) {
        let [x, y, w] = q.shift();
        if (x < 0 || y < 0 || x >= rows || y >= cols || maze[x][y] == "+") {
            continue;
        }
        if (
            (x != entrance[0] || y != entrance[1]) &&
            (x == 0 || y == 0 || x == rows - 1 || y == cols - 1)
        ) {
            return w;
        }
        q.push([x + 1, y, w + 1]);
        q.push([x, y + 1, w + 1]);
        q.push([x - 1, y, w + 1]);
        q.push([x, y - 1, w + 1]);
        //mark as visited
        maze[x][y] = "+";
    }
    return -1;
};
