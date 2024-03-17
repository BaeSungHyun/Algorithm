package algorithm.kotlin


fun main() {
    val numbers = listOf(1, -2, 3, -4, 5, -6)

    val anyNegative = numbers.any { it < 0 }
    val anyGT6 = numbers.any {it > 6}

    val allEven = numbers.all {it % 2 == 0 }
    val allLess6 = numbers.all { it < 6 }

    val _allEven = numbers.none { it % 2 == 1}
    val _allLess = numbers.none { it > 6 }


    println(anyNegative)
    println(anyGT6)
    println()

    println(allEven)
    println(allLess6)
    println()

    println(_allEven)
    println(_allLess)

}


