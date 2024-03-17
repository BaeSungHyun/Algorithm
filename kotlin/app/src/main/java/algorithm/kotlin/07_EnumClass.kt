package algorithm.kotlin

enum class State {
    IDLE, RUNNING, FINISHED // Each enum constant is an object
}

enum class Color(val rgb: Int) {
    RED(0xFF0000), // since it's instance of enum class, need to pass parameter to constructor
    GREEN(0x00FF00),
    BLUE(0x0000FF),
    YELLOW(0xFFFF00); // enum class members separated from the constant definitions by semicolon

    fun containsRed() = (this.rgb and 0xFF0000 != 0) // boolean operation
}

fun main() {
    val state = State.RUNNING
    val message = when (state) {
        State.IDLE -> "It's idle"
        State.RUNNING -> "It's running"
        State.FINISHED -> "It's finished"
    }
    println(message)

    val red = Color.RED
    println(red)
    println(red.containsRed())
    println(Color.BLUE.containsRed())
    println(Color.YELLOW.containsRed())
}