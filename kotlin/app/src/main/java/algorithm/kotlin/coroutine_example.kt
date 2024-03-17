package algorithm.kotlin

import kotlinx.coroutines.*
import kotlin.concurrent.thread

//
fun main() {
    runBlocking {// coroutine builder that bridges the non-coroutine world of a regualr 'fun main()'
        launch { // coroutine builder
            delay(1000L) // special suspending function
            println("World!")
        }

        launch {
            println("fuck")
            coroutineScope {  }
        }

        println("Hello")
        // Order of print is different
    }
    print("Blocked")
}

//fun main() = runBlocking{
//    launch {doWorld()}
//    println("hello")
//}
//
//suspend fun doWorld() {
//    delay(1000L)
//    println("world!")
//}


//fun main() = runBlocking {
//    doWorld()
//    print("Is it?")
//}
//
//suspend fun doWorld() {
//    coroutineScope {
//        launch {
//            delay(1000L)
//            println("World!")
//        }
//        println("Hello")
//    }
//}


//fun main() = runBlocking{
//    doWorld()
//    println("Done")
//}
//
//suspend fun doWorld() = coroutineScope {
//    launch {
//        delay(2000L)
//        println("World 2")
//    }
//    launch {
//        delay(1000L)
//        println("World 1")
//    }
//    println("Hello")
//}


// Explicit 'Job' obejct
//fun main() = runBlocking {
//    val job = launch {
//        delay(1000L)
//        println("World!")
//    }
//    println("Hello")
//    job.join() // suspend function. So runBlocking will wait for this to complete
//    println("Done")
//}


// Coroutines are less resource-intensive than JVM threads.
// Code that exhausts JVM's available memory when using threads can be expressed using coroutines without
// hitting resource limits.

//fun main() = runBlocking{
//    repeat(50_000) {
//        launch {
//            delay(5000L)
//            print(".")
//        }
//    }
//}

// Compare with above
//fun main() {
//    repeat(50_000) {
//        thread {
//            Thread.sleep(5000L)
//            print(".")
//        }
//    }
//}