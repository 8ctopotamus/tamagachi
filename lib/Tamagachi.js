class Tamagachi {
  naturalDeathAge = 1

  constructor(name) {
    if (!name) throw new Error('Tamagachi needs a name')
    this.name = name
    this.age = 0
    this.hp = 100
  }
}

Tamagachi.prototype.heartbeat = function() {
  this.age += (1 / 1000) * 100
  this.hp--
}

Tamagachi.prototype.draw = async function(worldTime) {
  const ears = '  /\\___ \\'

  let face = worldTime % 2 === 0 ? '^ U ^' : 'o _ o'

  if (this.hp <= 0) {
    face = 'x n x'
  }

  const rightArm = '\\'
  const leftArm = '/'

  const legs = '   L   L'

  console.log(`
    ${ears}
    ${leftArm}( ${face} )${rightArm}
    ${legs}
       ------
    Name: ${this.name}
    HP:   ${this.hp}%
    Age:  ${this.age.toFixed(2)}yrs
  `)
}

Tamagachi.prototype.isAlive = function() {
  return this.hp > 0
}

export default Tamagachi