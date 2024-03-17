package algorithm.kotlin

import androidx.lifecycle.ViewModel
import androidx.lifecycle.viewModelScope
import kotlinx.coroutines.flow.*
import kotlinx.coroutines.runBlocking
import java.math.*

// flow : flowBuilder API. Creates a cold flow from the given suspendable block. The flow being cold
//      means that the block is called every time a terminal operator is applied to the resulting flow.

fun fibonacci(): Flow<BigInteger> = flow {
    var x = BigInteger.ZERO
    var y = BigInteger.ONE

    while (true) {
        // emissions from flow builder are cancellable be default -- each call to emit also calls
        // ensureActive.
        emit(x)
        val temp = x
        x = y
        y += temp

//        x = y.also {
//            y += x
//        }
    }
}

/*
* Exception Code
* flow {
*   emit(1) // OK
*   withContext(Dispatcher.IO) {
*       emit(2)
*   }
* }
*
* 'emit' should happen strictly in the dispatchers of the block in order to preserve the flow context.
*
* If you want to switch the context of execution of a flow, use the 'flowOn' operator
* */

fun main() {
    runBlocking {
        fibonacci().take(100).collect { println(it) }
    }
}

class LatestNewsViewModel(
    private val newsRepository: String
) : ViewModel() {
    init {
        // viewModelScope.
    }
}