var addTwoPromises = async function(promise1, promise2) {
    const val1 = await promise1;
    const val2 = await promise2;
    return val1 + val2;
};