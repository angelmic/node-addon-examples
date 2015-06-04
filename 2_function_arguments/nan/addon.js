var addon = require('bindings')('addon.node')

console.log('This should be sum of :', addon.add(3, 5, 6, 9, 10, 200))