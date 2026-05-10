var TimeLimitedCache = function() {
    this.cache = new Map();
};

/** 
 * @param {number} key
 * @param {number} value
 * @param {number} duration
 * @return {boolean}
 */
TimeLimitedCache.prototype.set = function(key, value, duration) {
    const now = Date.now();

    let exists = false;

    // Check if key exists and is not expired
    if (this.cache.has(key)) {
        const data = this.cache.get(key);

        if (data.expire > now) {
            exists = true;
        }

        // Clear old timeout
        clearTimeout(data.timeoutId);
    }

    // Set timeout to delete key after duration
    const timeoutId = setTimeout(() => {
        this.cache.delete(key);
    }, duration);

    // Store value and expiry time
    this.cache.set(key, {
        value: value,
        expire: now + duration,
        timeoutId: timeoutId
    });

    return exists;
};

/** 
 * @param {number} key
 * @return {number}
 */
TimeLimitedCache.prototype.get = function(key) {
    const now = Date.now();

    if (!this.cache.has(key)) {
        return -1;
    }

    const data = this.cache.get(key);

    if (data.expire <= now) {
        this.cache.delete(key);
        return -1;
    }

    return data.value;
};

/** 
 * @return {number}
 */
TimeLimitedCache.prototype.count = function() {
    const now = Date.now();
    let count = 0;

    for (const [key, data] of this.cache) {
        if (data.expire > now) {
            count++;
        }
    }

    return count;
};

/**
 * const timeLimitedCache = new TimeLimitedCache()
 * timeLimitedCache.set(1, 42, 1000); // false
 * timeLimitedCache.get(1); // 42
 * timeLimitedCache.count(); // 1
 */