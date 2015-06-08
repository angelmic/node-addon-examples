var createObject = require('bindings')('addon');

console.log("##########################");
var obj = createObject(10);
console.log("##########################");
console.log( obj.plusOne() ); // 11
console.log( obj.plusOne() ); // 12
console.log( obj.plusOne() ); // 13

console.log("##########################");
console.log("##########################");
var obj2 = createObject(20);
console.log("##########################");
console.log( obj2.plusOne() ); // 21
console.log( obj2.plusOne() ); // 22
console.log( obj2.plusOne() ); // 23
