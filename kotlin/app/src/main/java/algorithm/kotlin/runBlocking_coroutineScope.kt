package algorithm.kotlin

import kotlinx.coroutines.asCoroutineDispatcher
import kotlinx.coroutines.*
import java.util.concurrent.Executors
import kotlin.system.measureTimeMillis

val context = Executors.newFixedThreadPool(2).asCoroutineDispatcher()

fun coroutineScope() = runBlocking {
    (1..10).forEach {
        launch(context) {
            println("Start No.$it in coroutineScope on ${Thread.currentThread().name}")
            delay(500)
            println("End No.$it in coroutineScope on ${Thread.currentThread().name}")
        }
    }
}

fun runBlocking() = runBlocking {
    (1..10).forEach {
        launch(context) {
            runBlocking {
                println("Start No.$it in runBlocking on ${Thread.currentThread().name}")
                delay(500)
                println("End No.$it in runBlocking on ${Thread.currentThread().name}")
                coroutineContext.cancelChildren()
            }
            coroutineContext.cancelChildren()
        }
    }
    if (!coroutineContext.isActive) {
        coroutineContext.cancelChildren()
        coroutineContext.cancel()
    }
}

fun main() {
    val timeInMills = measureTimeMillis {
//        coroutineScope()
        runBlocking()
    }
    println("coroutineScopeTimeInMills = $timeInMills")
}