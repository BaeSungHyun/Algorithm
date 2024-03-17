package algorithm.kotlin

// Taking functions as Parameters
fun calculate(x: Int, y: Int, operation: (Int, Int) -> Int): Int {
    return operation(x, y)
}
fun sum(x: Int, y: Int) = x + y


// Return Functions
fun operation(): (Int)->Int {
    return ::square
}
fun square(x: Int) = x * x

fun main() {
    // :: - notation that references a function by name
    println(calculate(7, 10, ::sum))
    println(calculate(10, 9) {x, y -> x * y})

    val func = operation()
    println(func(2))
}