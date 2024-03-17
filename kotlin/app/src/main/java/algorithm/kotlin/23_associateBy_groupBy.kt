package algorithm.kotlin

// Build map : key is defined in the KeySelector parameter. value is defined in optional valueSelector parameter.
// associateBy : uses the last suitable element as the 'value'
// groupBy : builds a list of all suitable elements and puts it in the 'value'


data class Person3(val name: String, val city: String, val phone: String)

val people = listOf(
    Person3("Bae", "Seoul", "010-2855-2237"),
    Person3("Han", "Nakseong", "010-4775-2534"),
    Person3("Chang", "Bangbae", "010-2653-2237"),
    Person3("Jeong", "Bangbae", "010-9945-2237")
)

fun main() {
    val phoneBook = people.associateBy { it.phone }
    println(phoneBook)

    val cityBook = people.associateBy(Person3::phone, Person3::city)
    println(cityBook)

    val peopleCities = people.groupBy(Person3::city, Person3::name)
    println(peopleCities)

    val lastPersonCity = people.associateBy(Person3::city, Person3::name)
    println(lastPersonCity)
}
