fun main() {
    val myNumbers = listOf(3, 7, 1, 0, 13, 17, 2, 6, 8)
    println("My numbers are $myNumbers")
    println("sorted ${myNumbers.sorted()}")

    val myNumbsDouble = myNumbers
        .filter { it > 5 }
        .map { it * 2 }
        .sorted()
    println("filtered, doubled and sorted $myNumbsDouble")
    println("and addition of the values ${myNumbsDouble.reduce { acc, it -> acc + it }}")
}