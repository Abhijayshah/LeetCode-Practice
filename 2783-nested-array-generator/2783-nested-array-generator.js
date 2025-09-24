/**
 * @param {Array} arr
 * @return {Generator}
 */
var inorderTraversal = function* (arr) {
    for (const item of arr) {
        if (Array.isArray(item)) {
            // Recursively yield values from the nested array
            yield* inorderTraversal(item);
        } else {
            // Yield the integer
            yield item;
        }
    }
};

// Example usage:
const gen = inorderTraversal([[[6]],[1,3],[]]);
console.log(gen.next().value); // 6
console.log(gen.next().value); // 1
console.log(gen.next().value); // 3
console.log(gen.next().done);  // true
