package algorithm.kotlin

// object keyword : obtain a data type with a single implementation. (Singleton pattern).
//              Only need to declare an 'object': no class, no constructor, only a lazy instance.
//              Why lazy? Because it will be created once when the object is accessed.
//              Otherwise, it won't even be created.

fun rentPrice(standardDays: Int, festivityDays: Int, specialDays: Int): Unit {
    val dayRates = object {
        var standard: Int = 30 * standardDays
        var festivity: Int = 50 * festivityDays
        var special: Int = 100 * specialDays
    }

    val total = dayRates.standard + dayRates.festivity + dayRates.special
    println("Total price: $total")
}

// object declaration : not an expression, and can't be used in a variable assignment.
//                  Use it to directly access its members
object DoAuth {
    fun takeParams(username: String, password: String) {
        println("input Auth parameters = $username:$password")
    }
}

// companion object - static methods or property
class BigBen {
    companion object Bonger {
        fun getBongs(nTimes: Int) {
            for (i in 1..nTimes) {
                println("BONG")
            }
        }
    }
}

fun main() {
    rentPrice(10, 2, 1)
    DoAuth.takeParams("foo", "qwerty")

    BigBen.getBongs(12)
}
