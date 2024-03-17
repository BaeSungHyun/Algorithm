package algorithm.kotlin

open class GrandParent {}
open class Parent: GrandParent() {}
class BabyChild : Parent() { }

fun main() {
    val parent: GrandParent = Parent()
    val babyChild : Parent = BabyChild()
    //val parent2: Parent = GrandParent()    // error !!!

}

// covariance : 공분산, can use more derived type
// contravariance : can use more generic type
// invariance : only specific type