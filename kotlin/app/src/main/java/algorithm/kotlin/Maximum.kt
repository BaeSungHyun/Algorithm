package algorithm.kotlin

import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    var max : Int = 0
    var maxIndex : Int = 1

    var number : Int
    for (i in 1..9) {
        number = br.readLine().toInt()
        if (max < number) {
            max = number
            maxIndex = i
        }
    }

    bw.write("$max\n$maxIndex")
    bw.flush()
}