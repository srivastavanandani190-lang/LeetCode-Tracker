/**
 * @param {Object|Array} obj
 * @return {Object|Array}
 */
var compactObject = function(obj) {
    
    // If obj is not an object or array, return it directly
    if (obj === null || typeof obj !== "object") {
        return obj;
    }

    // Handle arrays
    if (Array.isArray(obj)) {
        let result = [];

        for (let item of obj) {
            let compacted = compactObject(item);

            // Keep only truthy values
            if (Boolean(compacted)) {
                result.push(compacted);
            }
        }

        return result;
    }

    // Handle objects
    let result = {};

    for (let key in obj) {
        let compacted = compactObject(obj[key]);

        // Keep only truthy values
        if (Boolean(compacted)) {
            result[key] = compacted;
        }
    }

    return result;
};