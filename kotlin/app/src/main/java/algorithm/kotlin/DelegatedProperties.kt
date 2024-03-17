package algorithm.kotlin

import kotlin.reflect.KProperty

// Delegated properties that allows delegating the calls of the property set and get methods
// to a certain object.
// Delegate object should have the method getValue and for mutable properties need setValue

class Example {
    var p: String by Delegate()
}

class Delegate() {
    operator fun getValue(thisRef: Any?, prop: KProperty<*>): String { // Delegation methods
        return "$thisRef, thank you for delegating ${prop.name}"
    }

    operator fun setValue(thisRef: Any?, prop: KProperty<*>, value: String) { // Delegation methods
        println("$value has been assigned to ${prop.name} in $thisRef")
    }
}

// Standard Delegates from Kotlin standard library - lazy , observable
class LazySample {
    init {
        println("created!")
    }

    // Need for thread safety, use blockingLazy()
    val lazyStr: String by lazy {
        println("computed!")
        "my lazy"
    }
}

// Storing Properties in a Map - handy for tasks like parsing JSON or doing other "dynamic" stuff
class User2(val map: Map<String, Any?>) {
    val name: String by map
    val age: Int by map
}

fun main() {
    val e = Example()
    println(e.p)
    e.p = "NEW"

    println(e.p)


    val sample = LazySample() // lazy is not initialized on object creation
    println("lazyStr = ${sample.lazyStr}") // first call to get() executes the lambda expression passed to
    // lazy() as an argument and saves the result
    println(" = ${sample.lazyStr}") // further calls to get() return the saved result

    val user = User2(mapOf("name" to "John Doe", "age" to 25))
}