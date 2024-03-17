package algorithm.kotlin

// automatically derives the following members from all properties declared in the primary constructor:
// .equals() / .hashCode() pair
// .toString()
// .componentN() functions corresponding to the properties in their order of declaration
// .copy() function

data class User(val name: String, val id: Int) {
    override fun equals(other: Any?): Boolean {
        // type check : is
        return other is User && other.id == this.id
    }
}

fun main() {
    val user = User("Alex", 1)
    println(user)

    val secondUser = User("Alex", 1)
    val thirdUser = User("Max", 2)

    println("user == seconduser: ${user == secondUser}")
    println("user == thirdUser: ${user == thirdUser}")

    // hashCode() function
    println(user.hashCode())
    println(secondUser.hashCode()) // same hash code as above
    println(thirdUser.hashCode())

    // copy() function
    println(user.copy())
    println(user === user.copy())
    println(user.copy("Max"))
    println(user.copy(id = 3))

    println("name = ${user.component1()}")
    println("id = ${user.component2()}")
}