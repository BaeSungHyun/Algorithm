// Read jpg , png

#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ifstream input("./example05.jpg", ios::binary);

    // Copy all data into buffer
    // unsigned char : jpg or other files are usually in byte format.
    // char : designed to work with streams in a generic way.
    // {} : end-of-stream marker. std::istreambuf_iterator is default-constructed, it becomes a special value
    //                              indicating the end of the stream. It effectively serves as the "end" iterator.
    vector<unsigned char> buffer(istreambuf_iterator<char>(input), {});

    int x;
}