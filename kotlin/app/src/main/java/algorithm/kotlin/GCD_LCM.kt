package algorithm.kotlin

import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.StringTokenizer

fun gcd(a : Int, b : Int): Int {
    var x = a
    var y = b

    var temp = 0

    if (y > x) {
        temp = x
        x = y
        y = temp
    }

    while (y != 0) { // y == mod
        temp = x % y
        x = y // x == div
        y = temp
    }

    return x
}

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    val listNum = StringTokenizer(br.readLine())
    val a = listNum.nextToken().toInt()
    val b = listNum.nextToken().toInt()

    val gcdNum = gcd(a, b)
    val lcmNum = a * b / gcdNum

    bw.write("$gcdNum\n")
    bw.write("$lcmNum")

    bw.flush()
}