package algorithm.kotlin

import kotlin.system.*
import kotlinx.coroutines.*
import java.lang.ArithmeticException

suspend fun doSomethingUsefulOne(): Int {
    delay(1000L)
    return 13
}

suspend fun doSomethingUsefulTwo(): Int {
    delay(1000L)
    return 29
}

// Coroutine is Sequential by default
//fun main() {
//    runBlocking<Unit> {
//        val time = measureTimeMillis {
//            // coroutine is sequential by default
//            val one = doSomethingUsefulOne()
//            val two = doSomethingUsefulTwo()
//            println("The answer is ${one + two}")
//        }
//        println("Completed in $time ms")
//    }
//}


// Coroutine Concurrent using async
//fun main() {
//    runBlocking{
//        val time = measureTimeMillis {
//            // async is just like launch except that launch returns Job that doesn't carry value
//            // async returns 'Deferred' that represents a promise to return value later
//            val one = async { doSomethingUsefulOne() }
//            val two = async { doSomethingUsefulTwo() }
//            println("The answer is ${one.await()} + ${two.await()}")
//        }
//        println("Completed in $time ms")
//    }
//}


// Lazily started async
//fun main() {
//    runBlocking{
//        val time = measureTimeMillis {
//            // async is just like launch except that launch returns Job that doesn't carry value
//            // async returns 'Deferred' that represents a promise to return value later
//            val one = async(start = CoroutineStart.LAZY) { doSomethingUsefulOne() }
//            val two = async(start = CoroutineStart.LAZY) { doSomethingUsefulTwo() }
//            delay(500)
//
//            one.start()
//            two.start()
//
//            println("The answer is ${one.await()} + ${two.await()}")
//        }
//        println("Completed in $time ms")
//    }
//}



// Structured Concurrency hierarchy
fun main() {
    runBlocking {
        try {
            failedConcurrentSum()
        } catch (e: ArithmeticException) {
            println("Computation failed with ArithmeticException")
        }
    }
}

suspend fun failedConcurrentSum(): Int {
    return coroutineScope {
        val one = async<Int> {
            try {
                delay(Long.MAX_VALUE)
                42
            } finally {
                println("First child was cancelled")
            }
        }
        val two = async<Int> {
            println("Second child throws an exception")
            throw ArithmeticException()
        }
        one.await() + two.await()
    }
}