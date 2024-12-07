/**
 * @param {number} numCourses
 * @param {number[][]} prerequisites
 * @return {boolean}
 */
var canFinish = function (numCourses, prerequisites) {
    let adj = new Map();
    for (const edge of prerequisites) {
        let from = edge[0];
        let to = edge[1];
        if (from === to) {
            return false;
        }
        if (adj.get(from) === undefined) {
            adj.set(from, []);
        }
        adj.get(from).push(to);
    }

    let visited = new Set();
    for (const course of adj.keys()) {
        if (!dfs(adj, visited, course)) {
            return false;
        }
    }
    return true;
};

function dfs(adj, visited, course) {
    if (adj.get(course) === undefined) {
        return true;
    }
    if (visited.has(course)) {
        return false;
    }
    visited.add(course);
    for (const preq of adj.get(course)) {
        if (!dfs(adj, visited, preq)) {
            return false;
        }
    }
    visited.delete(course);
    adj.set(course, []);
    return true;
}
