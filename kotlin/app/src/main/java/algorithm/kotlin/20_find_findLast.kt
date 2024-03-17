package algorithm.kotlin

fun main() {
    val words = listOf("Lets", "find", "something", "in", "collection", "somehow")

    val first = words.find{it.startsWith("some")} // first element
    val last = words.findLast{it.startsWith("some")} // last element

    val nothing = words.find{it.contains("nothing")}

    println(first)
    println(last)
    println(nothing)

}