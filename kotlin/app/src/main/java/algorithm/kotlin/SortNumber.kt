package algorithm.kotlin

import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    val num : Int = br.readLine().toInt()

//    40,000,000 Byte = 40,000 KB = 40 MB ..?

    // Initialize to all 9
    // range 1 ~ 9,999
    val numArray : IntArray = IntArray(10_001) {
        0
    }

    for (i in 0..< num) {
        numArray[br.readLine().toInt()]++
    }

    for (i in 1.. 10_000) {
        while (numArray[i]-- > 0) {
            bw.write("$i\n")
        }
    }

    bw.flush()
}