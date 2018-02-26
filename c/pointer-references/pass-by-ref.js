function setX (obj) {
  obj.x = 1
}

const a = { x: 0 }
setX(a)

console.log(a.x) // 1

function setNull (obj) {
  obj = null
}

const b = { x: 0 }
setNull(b)

console.log(b) // { x: 0 }
