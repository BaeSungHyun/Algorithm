package algorithm.kotlin

import kotlinx.coroutines.*

fun main() {
    println(Thread.currentThread().name)

    runBlocking {
        launch {
            println("main runBlocking : I'm working in thread ${Thread.currentThread().name}")
        }

        launch(Dispatchers.Unconfined) {
            println("Unconfined : I'm working in thread ${Thread.currentThread().name}")
        }
        launch(Dispatchers.Default) {
            println("Default : I'm working in thread ${Thread.currentThread().name}")
        }

        // Dedicated thread is very expensive resource.
        // Must be either released, using the close function.
        // Or reused throughout the application.
        launch(newSingleThreadContext("MyOwnThread")) {
            println("newSingleThreadContext : I'm working in thread ${Thread.currentThread().name}")
        }
    }
}