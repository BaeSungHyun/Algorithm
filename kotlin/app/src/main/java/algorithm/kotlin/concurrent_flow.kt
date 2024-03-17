package algorithm.kotlin

import kotlinx.coroutines.*
import kotlinx.coroutines.flow.*
import kotlin.system.*

fun simple5() : Flow<Int> {
    return flow {
        for (i in 1..3) {
            delay(1000)
            emit(i)
        }
    }
}

fun main() {
    runBlocking {
        val time = measureTimeMillis {
            simple5().buffer() // run emit and collect concurrently
                .collect { value ->
                    delay(1000)
                    println(value)
                }
        }
        println("Collected in $time ms")
    }
}