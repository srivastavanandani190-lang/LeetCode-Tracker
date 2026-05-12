/**
 * @param {Function} fn
 * @return {Object}
 */
Array.prototype.groupBy = function(fn) {
    const grouped = {};

    for (const item of this) {
        const key = fn(item);

        if (!grouped[key]) {
            grouped[key] = [];
        }

        grouped[key].push(item);
    }

    return grouped;
};

/**
 * Example:
 */

const array = [
  {"id":"1"},
  {"id":"1"},
  {"id":"2"}
];

const result = array.groupBy(function(item) {
    return item.id;
});

console.log(result);

// Output:
// {
//   "1": [ { id: "1" }, { id: "1" } ],
//   "2": [ { id: "2" } ]
// }