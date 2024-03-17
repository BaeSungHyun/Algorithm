package algorithm.kotlin

// also is similar to apply but inside the block, the object is referenced by 'it', so it's easier
//      to pass it as an argument to a function.

fun main() {
    fun writeCreationLog(p: Person) {
        p.apply {
            println("Hi I am $name")
            println("and I am $age years old.")
        }
    }

    val jake2 = Person("jake", 45).also {
        writeCreationLog(it)
    }
}