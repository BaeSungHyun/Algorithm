package algorithm.kotlin

fun main() {
    // infix functions as extension function
    infix fun Int.times2(str: String) = str.repeat(this)
    println(2 times2 "Bye ")

    val sophia = Person2("Sophia")
    val claudia = Person2("Claudia")
    sophia likes claudia

    // operator functions
    operator fun Int.times(str: String) : String {
        return str.repeat(this)
    }
    println(2 * "Bye ")

    operator fun String.get(range: IntRange) : String {
        return substring(range)
    }
    val str = "Always forgive your enemies"
    println(str[0..14])


    // vararg Parameters - at runtime, it's just an array
    fun printAll(vararg messages: String) {
        for (m in messages) println(m)
    }
    fun log(vararg entries: String) {
        printAll(*entries) // special speard operator *
    }
    log("Hello", "Hallo", "Salut")
}

class Person2(val name: String) {
    val likedPeople = mutableListOf<Person2>()
    // infix function as class method
    infix fun likes(other: Person2) { likedPeople.add(other) }
}