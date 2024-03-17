package algorithm.kotlin

val systemUsers: MutableList<Int> = mutableListOf(1,2,3)
val sudoers: List<Int> = systemUsers // Polymorphism


fun addSystemuser(newUser: Int) {
    systemUsers.add(newUser)
}

fun getSysSudoers(): List<Int> {
    return sudoers
}

fun main() {
    addSystemuser(4)
    println("Total sudoers: ${getSysSudoers().size}")

    println(getSysSudoers()[1])

    getSysSudoers().forEach {
        i -> println("Some user $i")
    }
}