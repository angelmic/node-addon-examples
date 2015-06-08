var addon = require('bindings')('addon');

console.log("SSSSSSSSSSSSSSSS");
var obj = new addon.MyObject(10);
console.log("EEEEEEEEEEEEEEEEEEEE");
console.log( obj.plusOne() ); // 11
console.log( obj.plusOne() ); // 12
console.log( obj.plusOne() ); // 13

console.log("===================");
var obj2 = addon.MyObject(2);
console.log("###################");
console.log( obj2.plusOne() );


var obj3 = new addon.MyObject(55);
console.log("###################");
console.log( obj3.plusOne() );
