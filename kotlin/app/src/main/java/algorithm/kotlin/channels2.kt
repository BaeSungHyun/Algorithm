package algorithm.kotlin

import kotlinx.coroutines.*
import kotlinx.coroutines.channels.*

// Fan-out : Multiple coroutines receive from the same channel, distributing work
//          between themselves.
fun CoroutineScope.produceNumbers() = produce<Int> {
    var x = 1
    while (true) {
        send(x++)
        delay(100)
    }
}

fun CoroutineScope.launchProcessor(id: Int, channel: ReceiveChannel<Int>) = launch {
    for (msg in channel) {
        println("Processor #$id received $msg")
    }
}

fun main() {
    runBlocking<Unit> {
        val producer = produceNumbers()
        repeat(5) {
            launchProcessor(it, producer)
        }
        delay(950)
        producer.cancel() // cancel producer coroutine and thus kill them all
    }
}