/**
 * @param {string[]} words
 * @param {number} maxWidth
 * @return {string[]}
 */
var fullJustify = function (words, maxWidth) {
    let res = [];
    let n = words.length;
    let current_words = [];
    let current_length = 0;
    let spaces = 0;
    let i = 0;
    while (i < n) {
        if (current_length + spaces + words[i].length <= maxWidth) {
            current_words.push(words[i]);
            current_length += words[i].length;
            if (current_length + spaces + 1 <= maxWidth) {
                spaces++;
            }
            // if the word we just added is the last one
            if (i == n - 1) {
                let last = "";
                // left justify
                for (let j = 0; j < current_words.length; j++) {
                    last += current_words[j];
                    if (last.length != maxWidth) {
                        last += " ";
                    }
                }
                while (last.length < maxWidth) {
                    last += " ";
                }
                res.push(last);
                break;
            }
            i++;
        } else {
            res.push(distribute(current_words, current_length, maxWidth));
            // reset
            current_words = [];
            current_length = 0;
            spaces = 0;
        }
    }
    return res;
};
var distribute = (words, words_length, maxWidth) => {
    let res = "";
    let words_count = words.length;
    let total_spaces = maxWidth - words_length;
    let space_each = total_spaces;
    let remainder = 0;
    if (words.length > 1) {
        space_each = Math.floor(total_spaces / (words_count - 1));
        remainder = total_spaces - (words_count - 1) * space_each;
    }
    for (let i = 0; i < words.length; i++) {
        if (i < words.length - 1 || words.length == 1) {
            let space = space_each;
            if (remainder > 0) {
                space++;
                remainder--;
            }
            res += words[i] + " ".repeat(space);
        } else {
            res += words[i];
        }
    }
    return res;
};

// console.log("|" + distribute(["acknowledgment"], 16) + "|");
// console.log("|" + distribute(["This", "is", "an"], 16) + "|");

console.log(
    arraysEqual(
        fullJustify(
            ["This", "is", "an", "example", "of", "text", "justification."],
            16
        ),
        ["This    is    an", "example  of text", "justification.  "]
    )
);
console.log(
    arraysEqual(
        fullJustify(
            ["What", "must", "be", "acknowledgment", "shall", "be"],
            16
        ),
        ["What   must   be", "acknowledgment  ", "shall be        "]
    )
);
console.log(
    arraysEqual(
        fullJustify(
            [
                "Science",
                "is",
                "what",
                "we",
                "understand",
                "well",
                "enough",
                "to",
                "explain",
                "to",
                "a",
                "computer.",
                "Art",
                "is",
                "everything",
                "else",
                "we",
                "do",
            ],
            20
        ),
        [
            "Science  is  what we",
            "understand      well",
            "enough to explain to",
            "a  computer.  Art is",
            "everything  else  we",
            "do                  ",
        ]
    )
);

console.log(
    arraysEqual(
        fullJustify(
            [
                "ask",
                "not",
                "what",
                "your",
                "country",
                "can",
                "do",
                "for",
                "you",
                "ask",
                "what",
                "you",
                "can",
                "do",
                "for",
                "your",
                "country",
            ],
            16
        ),
        [
            "ask   not   what",
            "your country can",
            "do  for  you ask",
            "what  you can do",
            "for your country",
        ]
    )
);

console.log(
    arraysEqual(
        fullJustify(
            [
                "When",
                "I",
                "was",
                "just",
                "a",
                "little",
                "girl",
                "I",
                "asked",
                "my",
                "mother",
                "what",
                "will",
                "I",
                "be",
                "Will",
                "I",
                "be",
                "pretty",
                "Will",
                "I",
                "be",
                "rich",
                "Here's",
                "what",
                "she",
                "said",
                "to",
                "me",
                "Que",
                "sera",
                "sera",
                "Whatever",
                "will",
                "be",
                "will",
                "be",
                "The",
                "future's",
                "not",
                "ours",
                "to",
                "see",
                "Que",
                "sera",
                "sera",
                "When",
                "I",
                "was",
                "just",
                "a",
                "child",
                "in",
                "school",
                "I",
                "asked",
                "my",
                "teacher",
                "what",
                "should",
                "I",
                "try",
                "Should",
                "I",
                "paint",
                "pictures",
                "Should",
                "I",
                "sing",
                "songs",
                "This",
                "was",
                "her",
                "wise",
                "reply",
                "Que",
                "sera",
                "sera",
                "Whatever",
                "will",
                "be",
                "will",
                "be",
                "The",
                "future's",
                "not",
                "ours",
                "to",
                "see",
                "Que",
                "sera",
                "sera",
                "When",
                "I",
                "grew",
                "up",
                "and",
                "fell",
                "in",
                "love",
                "I",
                "asked",
                "my",
                "sweetheart",
                "what",
                "lies",
                "ahead",
                "Will",
                "there",
                "be",
                "rainbows",
                "day",
                "after",
                "day",
                "Here's",
                "what",
                "my",
                "sweetheart",
                "said",
                "Que",
                "sera",
                "sera",
                "Whatever",
                "will",
                "be",
                "will",
                "be",
                "The",
                "future's",
                "not",
                "ours",
                "to",
                "see",
                "Que",
                "sera",
                "sera",
                "What",
                "will",
                "be,",
                "will",
                "be",
                "Que",
                "sera",
                "sera...",
            ],
            60
        ),
        [
            "When  I was just a little girl I asked my mother what will I",
            "be  Will  I be pretty Will I be rich Here's what she said to",
            "me  Que  sera sera Whatever will be will be The future's not",
            "ours  to see Que sera sera When I was just a child in school",
            "I asked my teacher what should I try Should I paint pictures",
            "Should  I  sing  songs This was her wise reply Que sera sera",
            "Whatever  will  be  will be The future's not ours to see Que",
            "sera  sera  When  I  grew  up  and  fell  in love I asked my",
            "sweetheart  what lies ahead Will there be rainbows day after",
            "day  Here's  what  my sweetheart said Que sera sera Whatever",
            "will  be  will be The future's not ours to see Que sera sera",
            "What will be, will be Que sera sera...                      ",
        ]
    )
);

function arraysEqual(a, b) {
    if (a === b) return true;
    if (a == null || b == null) return false;
    if (a.length !== b.length) return false;
    for (var i = 0; i < a.length; ++i) {
        if (a[i] !== b[i]) return false;
    }
    return true;
}
