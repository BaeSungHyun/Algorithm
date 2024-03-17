package algorithm.kotlin

import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import kotlin.time.measureTime

const val R = 31
const val M = 1234567891

fun hashing(x: String, y : Int) : Long {
    var sum: Long = 0
    var temp: Long

    for (i in 0..< y) {
        temp = ((x[i].code - 96) % M).toLong()
        for (j in 0..< i) {
            temp = (temp * R) % M
        }

        sum = (sum + temp) % M
    }

    return sum % M
}

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    val stringLen = br.readLine().toInt()
    val string = br.readLine()


    val timeTaken = measureTime {
        bw.write("${hashing(string, stringLen)}\n")

    }
    bw.write("$timeTaken")
    bw.flush()
}