package algorithm.kotlin

import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    val testCase : Int = br.readLine().toInt()

    val apartment : IntArray = IntArray(210 + 1 ) {0}

    for (k in 0..14) {
        for (n in 1..14) {
            if (k == 0) {
                apartment[n] = n
            } else if (n == 1) {
                apartment[14 * (k) + n] = apartment[14 * (k - 1) + n]
            } else {
                apartment[14 * k + n] = apartment[14 * k + n - 1] + apartment[14 * (k - 1) + n]
            }
        }
    }

    for (i in 0..<testCase) {
        val k = br.readLine().toInt()
        val n = br.readLine().toInt()

        bw.write("${apartment[14 * k + n]}\n")
    }
    bw.flush()
}