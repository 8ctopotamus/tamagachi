import inquirer from "inquirer"
import Tamagachi from "./Tamagachi.js"

class World {
  time = 0
  interval = null

  constructor() {
    
  }

  tick = () => {
    // redraw the screen
    console.clear() 
    // loop through tamagachis
    for (const t of this.tamagachis) {
      t.heartbeat()
      t.draw(this.time)
    }
    // check if all tamagachis are dead
    if (this.tamagachis.every(t => !t.isAlive())) {
      clearInterval(this.interval)
      console.log(":( Your Tamagachis have died")
    }
    this.time++
  }
}

World.prototype.bigBang = async function() {
  // A tamagachi is born
  this.tamagachis = [ new Tamagachi('Tama') ]
  clearInterval(this.interval)
  this.interval = setInterval(this.tick, 1000)
}

World.prototype.promptActions = async function() {
  const { action } = await inquirer.prompt([
    {
      type: "input",
      message: "What do you want to do?",
      name: "action"
    }
  ])
  console.log(action)
}

export default World