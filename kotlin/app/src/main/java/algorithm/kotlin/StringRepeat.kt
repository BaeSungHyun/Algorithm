package algorithm.kotlin

import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    var testCase : Int = br.readLine().toInt()

    var inputNum : Int
//    var input : CharSequence
    var inputString : String
    var x : List<String>

    while (testCase > 0) {
        x = br.readLine().split(" ")
        inputNum = x[0].toInt()
        inputString = x[1]

//        input = StringBuilder(inputNum * inputString.length)
//
//        for (element in inputString) {
//            for (i in 0..<inputNum) {
//                input.append(element)
//            }
//        }

//        bw.write("$input\n")

        for (element in inputString) {
            for (i in 0..< inputNum) {
                bw.write("$element")
            }
        }

        bw.write("\n")
        testCase--
    }

    bw.flush()
}