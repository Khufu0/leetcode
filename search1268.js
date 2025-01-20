/*
class Node {
    // maps char to Node
    map = new Map();
    end = false;
}

class Trie {
    #m_node = new Node();

    insert(word) {
        let node = this.#m_node;
        for (let char of word) {
            if (!node.map.has(char)) {
                node.map.set(char, new Node());
            }
            node = node.map.get(char);
        }
        node.end = true;
    }

    search(word) {
        let node = this.#m_node;
        for (let char of word) {
            if (!node.map.has(char)) {
                return false;
            }
            node = node.map.get(char);
        }
        return node.end;
    }

    startsWith(prefix) {
        let node = this.#m_node;
        for (let char of prefix) {
            if (!node.map.has(char)) {
                return false;
            }
            node = node.map.get(char);
        }
        return true;
    }

    getWords(prefix) {
        let node = this.#m_node;
        // advance to the last node of prefix
        for (let char of prefix) {
            if (!node.map.has(char)) {
                return [];
            }
            node = node.map.get(char);
        }
        let res = [];
        this.#dfs(node, prefix, res);
        return res;
    }

    #dfs(node, prefix, res) {
        if (res.length === 3) return;
        if (node.end) res.push(prefix);
        for (let i = 0; i < 26; i++) {
            let char = String.fromCharCode(97 + i);
            if (node.map.has(char)) {
                this.#dfs(node.map.get(char), prefix + char, res);
            }
        }
    }
}


var suggestedProducts = function (products, searchWord) {
    let trie = new Trie();
    products.forEach((product) => trie.insert(product));
    let res = [];
    for (let i = 1; i <= searchWord.length; i++) {
        let prefix = searchWord.slice(0, i);
        let words = trie.getWords(prefix);
        res.push(words.slice(0, 3));
    }
    return res;
};
*/

/**
 * @param {string[]} products
 * @param {string} searchWord
 * @return {string[][]}
 */
var suggestedProducts = function (products, searchWord) {
    let res = [];
    products.sort();
    for (let i = 1; i <= searchWord.length; i++) {
        let prefix = searchWord.slice(0, i);
        let words = products.filter((product) => product.startsWith(prefix));
        res.push(words.slice(0, 3));
    }
    return res;
};
