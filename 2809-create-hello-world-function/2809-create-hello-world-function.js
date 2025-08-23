/**
 * @return {Function}
 */
var createHelloWorld = function() {
    /**
     * This inner function is what gets returned by createHelloWorld.
     * It uses the rest parameter syntax (...args) to accept any number of arguments,
     * but it doesn't use them. It simply returns the required string.
     */
    return function(...args) {
        return "Hello World";
    }
};

/**
 * Example Usage:
 * const f = createHelloWorld();
 * console.log(f()); // "Hello World"
 * console.log(f({}, null, 42)); // "Hello World"
 */