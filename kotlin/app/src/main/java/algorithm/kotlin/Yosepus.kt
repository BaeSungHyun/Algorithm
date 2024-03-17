package algorithm.kotlin

import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.LinkedList
import java.util.StringTokenizer

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    val input = StringTokenizer(br.readLine())

    val N = input.nextToken().toInt()
    val K = input.nextToken().toInt()

    val list : LinkedList<Int> = LinkedList(List<Int>(N) {
                                            it + 1
                                    })

    bw.write("<")
    var target : Int
    while (list.isEmpty().not()) {
        for (i in 1..K) {
            target = list.pop()
            if (i != K) {
                list.addLast(target)
            } else {
                bw.write("$target")
            }
        }
        if (list.isEmpty().not())
            bw.write(", ")
    }
    bw.write(">")

    bw.flush()
}