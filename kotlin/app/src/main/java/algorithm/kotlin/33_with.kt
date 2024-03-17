package algorithm.kotlin

// non extension function that can access members of its argument concisely:
//      okay to omit the instance name when referring to its members

data class Config(val host: String, val port: String)

fun main() {
    val configuration = Config("localhost", "8000")
    with (configuration) {
        println("$host: $port")
    }
}