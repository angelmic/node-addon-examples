var addon = require('bindings')('addon');



addon.gg(function(msg, m2){
  console.log(msg.length, msg); // 'hello world'
  console.log(m2.length, m2); // 'hello world'
});

addon.dd(function(msg, m2){
  console.log(msg.length, msg); // 'hello world'
  console.log(m2.length, m2); // 'hello world'
});


//console.log(addon.gg());