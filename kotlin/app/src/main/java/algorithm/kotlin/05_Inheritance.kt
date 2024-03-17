package algorithm.kotlin

// Inheritance
open class Dog {
    open fun sayHello() {
        println("wow wow!")
    }
}
class Yorkshire: Dog() {
    override fun sayHello() {
        println("wlf wlf!")
    }
}

// Inheritance with Parameterized Constructor
open class Tiger(val origin: String) {
    fun sayHello() {
        println("A tiger from $origin says: grrrh!")
    }
}

class SiberianTiger(name: String): Tiger(name)

fun main() {
    val dog: Dog = Yorkshire()
    dog.sayHello()

    val tiger: Tiger = SiberianTiger("Sexy")
    tiger.sayHello()
}