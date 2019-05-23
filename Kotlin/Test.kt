fun main() {
    println("Hello world!")

    val age = askFromUser("Age").toIntOrNull() ?: -1

    println("Hello ${askFromUser("First Name")} ${askFromUser("Last Name")}!\nYou are $age old.")

    if (age >= 18) println("You have the right to vote.")
    else println("You are too jung.")
}

fun askFromUser(what: String): String {
    print("Please give your $what: (then press enter)")

    var input: String? = null
    while (input == null || input.trim() == "") input = readLine()

    return input
}