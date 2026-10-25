/**
 * @return {Function}
 */
var createHelloWorld = function() {
    function f() {
        return "Hello World";
    }
    
    return function(...args) {
        return f();
    }
};

/**
 * const f = createHelloWorld();
 * f(); // "Hello World"
 */