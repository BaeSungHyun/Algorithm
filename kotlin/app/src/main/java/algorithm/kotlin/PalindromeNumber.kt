package algorithm.kotlin

import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))


    var input : String = br.readLine()

    while (input != "0") {
        val size = input.length
        var index: Int = 0
        while (index <= size - index - 1 && input[index] == input[size - index++ - 1]) {
        }

        if (input[--index] == input[size - index - 1]) {
            bw.write("yes\n")
        } else {
            bw.write("no\n")
        }
        input = br.readLine()
    }

    bw.flush()
}