package algorithm.kotlin

import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    val NM = br.readLine().split(" ").map{
        it.toInt()
    }
    val M = NM[1]

    val input = br.readLine().split(" ").map {
        it.toInt()
    }.toIntArray()

    var sum : Int = Int.MIN_VALUE
    var temp : Int

    loop@ for (i in input.indices) {
        for (j in i + 1 ..< input.size) {
            for (k in j + 1..<input.size) {
                temp = input[i] + input[j] + input[k]
                if (M - temp == 0) {
                    sum = temp
                    break@loop
                }
                if (M - temp > 0 && (sum < temp) ) {
                    sum = temp
                }
            }
        }
    }

    bw.write("$sum")
    bw.flush()
}