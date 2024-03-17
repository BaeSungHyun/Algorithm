package algorithm.kotlin

import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    val numbers = br.readLine().split(" ")

    val diff = numbers[0].toInt() - numbers[1].toInt()
    var C = numbers[2].toInt() - numbers[0].toInt()

    var count = 1

    if (C > 0) {
        count += C / diff + (if (C % diff != 0) 1 else 0)
    }

    bw.write("$count")
    bw.flush()
}