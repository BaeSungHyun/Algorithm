package algorithm.kotlin

// scoping and null-checks
// called on an object, 'let' executes the given block of code and returns the result of its last expression.
// The object is accessible inside the block by the reference 'it'.

fun customPrint(str: String) {
    println(str.uppercase())
}

fun main() {
    val empty = "test".let {
        customPrint(it)
        it.isEmpty()
    }
    println(empty)

    fun printNonNull(str: String?) {
        println("Printing \"$str\": ")

        str?.let{
            print("\t")
            customPrint(it)
            println()
        }
    }

    printNonNull(null)
    printNonNull("my string")
}