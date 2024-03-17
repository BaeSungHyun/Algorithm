package algorithm.kotlin

import kotlinx.coroutines.*
import kotlinx.coroutines.channels.*

// 1.
//fun main() {
//    runBlocking {
//        val channel = Channel<Int>()
//        launch {
//            // CPU-consuming computation
//            for (x in 1..5) channel.send(x * x)
//            channel.close()
//        }
//
//        launch {
//            println("hi")
//        }
//        repeat(5) {println(channel.receive())}
//        println("Done!")
//    }
//}

// Unlike queue, channel can be closed to indicate that no more elements are coming.
// Conceptually, a 'close' is like sending a speical token to the channel.
// iteration stops as soon as this close token is received, so there is a guarantee that
// all previously sent elements before the close are received:



// 2. Building Channel Producers - Easy way
//fun CoroutineScope.produceSquares(): ReceiveChannel<Int> {
//    return produce {
//        for (x in 1..5) send(x * x)
//    }
//}
//
//fun main() {
//    runBlocking {
//        val squares = produceSquares()
//        squares.consumeEach { println(it) }
//        println("Done!")
//    }
//}


// 3. Pipelines - one coroutine is producing, possibly infinite, stream of values:
//fun CoroutineScope.produceNumbers(): ReceiveChannel<Int> {
//    return produce<Int> {
//        var x = 1
//        while (true) send(x++)
//    }
//}
//
//fun CoroutineScope.square(numbers: ReceiveChannel<Int>) : ReceiveChannel<Int> {
//    return produce {
//        for (x in numbers) send(x * x)
//    }
//}
//
//fun main() {
//    runBlocking {
//        val numbers = produceNumbers()
//        val squares = square(numbers)
//        repeat(5) {
//            println(squares.receive())
//        }
//        println("Done!")
//        coroutineContext.cancelChildren() // cancel children coroutines
//    }
//}


// 4. Prime numbers with pipeline
fun CoroutineScope.numbersFrom(start: Int) = produce<Int> {
    var x = start
    while (true) send(x++) // infinite stream of integers from start
}

fun CoroutineScope.filter(numbers: ReceiveChannel<Int>, prime: Int): ReceiveChannel<Int> {
    return produce<Int> {
        for (x in numbers) {
            if (x % prime != 0) {
                send(x)
            }
        }
    }
}

fun main() {
    runBlocking {
        var cur = numbersFrom(2) // infinitely send numbers...
        var temp: ReceiveChannel<Int>?
        repeat(10) {
            val prime = cur.receive() // retrieve only one element
            println(prime)
            cur = filter(cur, prime) // new Receive
        }
        coroutineContext.cancelChildren()
//        cur.cancel()
        println(cur.isClosedForReceive)
//        coroutineContext.cancel()
    }
}