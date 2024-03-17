package algorithm.kotlin

// sealed class can only be subclassed from inside the same package where the sealed class is declared
sealed class Mammal(val name: String)

class Cat(val catName: String) : Mammal(catName)
class Human(val humanName: String, val job: String) : Mammal(humanName)

fun greetMammal(mammal: Mammal): String {
    return when (mammal) {
        // smart cast by 'is'
        is Human -> "Hello ${mammal.name}; You're working as a ${mammal.job}"
        // smart cast by 'is'
        is Cat -> "Hello ${mammal.name}"
    } // doesn't need 'else' because it's sealed class. Compiler already knows it.
}

fun main() {
    println(greetMammal(Cat("Snowy")))
}

