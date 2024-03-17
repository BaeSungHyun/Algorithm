package algorithm.kotlin

// executes a block of code on an object and returns the object itself.
// Inside code block, object is referenced by this.

fun main() {
    val jake = Person(null, null)

    val stringDescription = jake.apply {
        name = "jake"
        age = 30
    }.toString()

    println(stringDescription)
}