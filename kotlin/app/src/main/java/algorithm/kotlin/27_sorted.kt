package algorithm.kotlin

import kotlin.math.abs

fun main() {
    // ascending by default
    val shuffled = listOf(5, 4, 2, 1, 3, -10)
    val natural = shuffled.sorted() // new memory

    val inverted = shuffled.sortedBy{ -it }
    val descending = shuffled.sortedDescending()
    val descendingBy = shuffled.sortedByDescending { abs(it) }

    println(natural)
    println(inverted)
    println(descending)
    println(descendingBy)
}