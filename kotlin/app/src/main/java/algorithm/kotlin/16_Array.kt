package algorithm.kotlin

/*
* Built-Int types
*   Type        Size (bits)     Min Value                   Max Value
*   Byte        8               -128                    127
*   Short       16              -32768                  32767
*   Int         32              -2147483648             2147483647
*   Long        64              -9223372036854775808    9223372036854775807
*
*   UByte       8               0                       255
*   UShort      16              0                       65535
*   UInt        32              0                       4294967295
*   ULong       64              0                       18446744073709551615
*
*   Char        16 (in JVM)
*
*   Type        Size (bits)     Significant bits            Exponent bits           Decimal bits
*   Float       32              24                          8                       6-7
*   Double      64              53                          11                      15-16
*
*   .toByte() , toShort() , toInt() , toLong() , toFloat() , toDouble()
*   Bitwise operations: shl(bits) shr(bits) ushr(bits) and(bits) or(bits) xor(bits) inv()
*
*   Boolean usually 8 bits in JVM. || && !
*
*   String: immutable , use StringBuilder if there is alot of modification
*
* */


// Array is Part of Basic type in Kotlin
/*
* Array : fixed number of values of the same type or its subtypes
*       Using primitives with 'Array' class may impoact performance because
*       primitives are boxed into objects. Thus, use primitive-type arrays instead.
*
* arrayOf() arrayOfNulls() emptyArray()
* .contentEquals() .contentDeepEquals()
* .sum() .shuffle()
* .toList() .toSet() .toMap() (Need pair value inside array)
*
* BooleanArray
* ByteArray
* CharArray
* DoubleArray
* FloatArray
* IntArray
* LongArray
* ShortArray
*
* UByteArray
* UShortArray
* UIntArray
* ULongArray
* */
