package algorithm.kotlin

fun main(args: Array<String>) {
    val name = "stranger"
    println("Hi $name!")
    print("Current count:")
    for (i in 0..10) {
        print(" $i")
    }
    println()

    val sum: (Int, Int) -> Int = { x: Int, y: Int -> x + y }

    println(sum(1, 2))

    val person: Person = Person("bae", null)

    with(person) {
        println(this.name)
        print(age)
    }
}

class Person constructor(var name: String?, var age: Int?) {
}



