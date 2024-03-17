package algorithm.kotlin

// map : [] operator returns the value corresponding to the given key, or null if there is no such key in the map
// 'getValue' function returns an existing value corresponding to the given key or throws an exception if
//      the key wasn't found. For maps created with 'withDefault', 'getValue' returns the default value
//      instead of throwing an exception.

fun main() {
    val map = mapOf("key" to 42)

    val value1 = map["key"]
    val value2 = map["key2"]

    println(value1)
    println(value2)

    val value3: Int = map.getValue("key")
    println(value3)

    val mapWithDefault = map.withDefault { k -> k.length }
    val value4 = mapWithDefault.getValue("key2")

    println(mapWithDefault === map)
    println(mapWithDefault == map)

    println(value4)


    try {
        map.getValue("anotherKey")
    } catch (e: NoSuchElementException) {
        println("Message: $e")
    }
}