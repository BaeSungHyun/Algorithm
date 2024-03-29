package algorithm.kotlin

fun main() {
    val numbers = listOf(1, -2, -3, -4, 5, -6)

    val doubled = numbers.map{ x -> x * 2 }
    val tripled = numbers.map{ it * 3 }

    doubled.forEach {
        println(it)
    }

    tripled.forEach {
        println(it)
    }
}

