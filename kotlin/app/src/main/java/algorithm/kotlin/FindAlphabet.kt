package algorithm.kotlin

import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    val input = br.readLine()
    val alphabets = Array<Int>(26) {
        -1
    }


    for (i in input.indices) {
        if (alphabets[(input[i]).code - 97] == -1)
            alphabets[(input[i]).code - 97] = i
    }

    for (i in alphabets) {
        bw.write("${i} ")
    }
    bw.flush()
}