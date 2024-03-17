package algorithm.kotlin

import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

//    val answer: Array<Long?> = arrayOfNulls(100)
    val answer: LongArray = LongArray(100)
    answer[0] = 1
    answer[1] = 1
    answer[2] = 1

    for (i in 3..99) {
        answer[i] = answer[i - 3] + answer[i - 2]
    }

    val T: Int = br.readLine().toInt()

    var N: Int = 0
    for (i in 1..T) {
        N = br.readLine().toInt()

        bw.write("${answer[N - 1]}\n")
    }

    bw.flush()
}