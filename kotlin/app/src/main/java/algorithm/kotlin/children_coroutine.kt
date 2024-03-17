package algorithm.kotlin

import kotlinx.coroutines.*

// when a coroutine is launched in the CoroutineScope of another coroutine,
// it inherits its context via CoroutineScope.coroutineContext and the Job of the
// new coroutine becomes a 'child' of the parent coroutine's job.
// When the parent coroutine is cancelled, all its children are recursively cancelled, too.

// This parent-child relation can be explicitly overriden by:
//   1. when a different scope is explicitly specifed when launching a coroutine (GlobalScope.launch)
//   2. When a different Job object is passed as the context for the new coroutine

fun main() {
    runBlocking {
        val request = launch {
            launch(Job()) {
                println("job1 : I run in my own job and execute in my own job")
                delay(1000)
                println("job1 : not affected by cancellation of the request")
            }

            launch {
                delay(100)
                println("job2 : I am a child of the request coroutine")
                delay(1000)
                println("job2 : I will not execute this line if my parent cancel")
            }
        }

        delay(500)
//        request.cancel()
        request.join() // Not necessary, because parent always waits for chlid scope to end
        println("main: who has survived request cancellation?")
        delay(1000)
    }
}