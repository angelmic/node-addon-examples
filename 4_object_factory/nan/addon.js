var addon = require('./build/Release/addon');

var obj1 = addon('gggghello', 1);
var obj2 = addon('ccccworld', 2);
console.log(obj1.msg+' '+obj2.msg);
console.log(obj1.num, obj2.num);

console.log(obj1.FnGG());