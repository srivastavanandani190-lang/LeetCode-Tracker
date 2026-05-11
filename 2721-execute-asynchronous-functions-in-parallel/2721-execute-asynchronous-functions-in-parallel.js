/**
 * @param {Array<Function>} functions
 * @return {Promise<any>}
 */
var promiseAll = function(functions) {
    return new Promise((resolve, reject) => {
        let results = new Array(functions.length);
        let completed = 0;

        // Edge case: empty array
        if (functions.length === 0) {
            resolve([]);
            return;
        }

        functions.forEach((fn, index) => {
            fn()
                .then((value) => {
                    results[index] = value;
                    completed++;

                    // If all promises resolved
                    if (completed === functions.length) {
                        resolve(results);
                    }
                })
                .catch((error) => {
                    // Reject immediately on first rejection
                    reject(error);
                });
        });
    });
};

/**
 * const promise = promiseAll([
 *   () => new Promise(res => res(42))
 * ]);
 * 
 * promise.then(console.log); // [42]
 */