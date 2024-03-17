package algorithm.kotlin

// executes a code block and returns its result
// difference with 'let' : inside 'run', the object is accessed by 'this'
// Useful, when you want to call object's methods rather than pass it as an argument.

fun getNullableLength(ns : String?): Int? {
    println("for \"$ns\" : ")

    return ns?.run {
        println("\tis empty? " + isEmpty())
        println("\tlength = $length")
        length
    }
}

fun main() {
    println(getNullableLength(null))

    println(getNullableLength(""))

    println(getNullableLength("some string"))

}

