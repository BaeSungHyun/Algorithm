package algorithm.kotlin

import kotlinx.coroutines.*
import kotlinx.coroutines.flow.*

// List
fun simple(): List<Int> = listOf(1, 2, 3)
// Sequence
fun simple1(): Sequence<Int> {
    return sequence {
        for (i in 1..3) {
            Thread.sleep(1000)
            yield(i)
        }
    }
}
// Suspending Functions
suspend fun simple2(): List<Int> {
    delay(1000)
    return listOf(1, 2, 3)
}
// Flow : async + sequence
fun simple3(): Flow<Int> {
    return flow {
        for (i in 1..3) {
            delay(1000)
            emit(i) // emitted
        }
    }
}

// Flows are cold : doesn't run until the flow is collected (like sequences)
fun simple4() : Flow<Int> { // flow is not suspend function
    return flow {
        println("Flow started")
        for (i in 1..3) {
            delay(1000)
            emit(i)
        }
    }
}


fun main() {
    simple().forEach{ value -> println(value) }
    simple1().forEach{ value -> println(value) }

    runBlocking {
        simple2().forEach { value -> println(value) }

        launch {
            for (k in 1..3) {
                println("I'm not blocked $k")
                delay(1000)
            }
        }
        // collects emitted value
        simple3().collect { value -> println(value)} // 'emit' lambda function as parameter to collect method

        println("Calling simiple function...")
        val flow = simple4()
        println("Calling collect...")
        flow.collect{ value -> println(value) }
        println("Calling collect again...")
        flow.collect { value -> println(value) }
    }
}