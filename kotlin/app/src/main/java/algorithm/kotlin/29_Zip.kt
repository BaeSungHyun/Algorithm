package algorithm.kotlin

// zip : merges two given collections into a new collection. By default, the result collection contains
//          Pairs of source collection elements with the same index. However, you can define your own
//          structure of the result collection element.

fun main() {
    val A = listOf("a", "b", "c")
    val B = listOf(1, 2, 3, 4)

    val resultPairs = A zip B
    val resultReduce = A.zip(B) { a, b -> "$a$b"}

    println(resultPairs) // Prints pairs
    println(resultReduce)
}