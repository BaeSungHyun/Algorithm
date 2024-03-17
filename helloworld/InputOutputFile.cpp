// ofstream
// ifstream
// fstream

// mode : ios::in , ios::out , ios::binary , ios::ate , ios::ape , ios::trunc 

// 1. Open a file is represented by a 'stream'. 
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


// Example
// void SendFile(int sock) {
//   std::ifstream image("image.jpg", std::ifstream::binary);
//   char buffer[1024];
//   int flags = 0;
//   while(!image.eof() ) {
//     image.read(buffer, sizeof(buffer));
//     if (send(sock, buffer, image.gcount(), flags)) {
//       ; // handle error
//     }
//   }
// }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 1. Write to text file
    ofstream myfile1 ("example.txt");
    if (myfile1.is_open()) {
        myfile1 << "This is a line.\r\n";
        myfile1 << "Sexy King.\n";
        myfile1 << "Still working with r?\n\r";
        myfile1.close();
    }

    // 2. Read text file
    string line;
    ifstream myfile2 ("example.txt");
    if (myfile2.is_open()) {
        while (getline(myfile2, line))
            cout << line << "\n";
        myfile2.close();
    }

    // 3. Calculate size of binary file
    // seekg (offset, direction = optinoal) : get
    // seekp (offset, direction = optional) : put
    streampos begin, end;
    ifstream myfile3("example.txt", ios::binary);
    begin = myfile3.tellg();
    myfile3.seekg(0, ios::end); // ios::end becomes the start
    end = myfile3.tellg();
    cout << "size is : " << (end - begin) << " bytes.\n";

    // 4. Binary files operations
    // For binary files, reading and writing data with the extension and insertion operators (<< and >>) and functions like 'getline' 
    // is not efficient, since we do not need to format any data and data is likely not formatted in lines.
    // write (memory_block , size)
    // read (memory_block , size)
    streampos size;
    char *memblock;

    ofstream myfile5("example05_bin.bin", ios::out | ios::binary );
    ifstream myfile4("example05.jpg", ios::in | ios::binary | ios::ate); // last of file position
    if (myfile4.is_open()) {
        size = myfile4.tellg();
        memblock = new char[size];

        myfile4.seekg(0, ios::beg);
        myfile4.read(memblock, size);
        myfile4.close();

        cout << "size of file : " << size << "\n";
        cout << memblock << "\n";
        
        size_t size_memblock {0};

        // memblock is char* but needs to be converted into 
        
        for (int i = 0; i < static_cast<int>(size) && myfile5.is_open(); i++) {
            unsigned char temp = memblock[i];
            unsigned char temp2 = (unsigned char)memblock[i];
            myfile5 <<  (unsigned char)memblock[i];
        }
        myfile5.close();

        delete[] memblock;
    }

    cout.flush();


    return 0;
}

// Buffers and Synchronization
// Stream are associated with internal buffer object of type 'streambuf'. This buffer object
// may represent a memory block that acts as an intermediary between the stream and the physical file.

// For example, with an ofstream, each time the member function put (which writes a single character),
// is called, the character may be inserted in this intermediate buffer instead of being written directly
// to the physical file with which the stream is associated.

// 1. When the file is closed: before closing a file, 
//      all buffers that have not yet been flushed are synchronized and all pending data is written or read to the physical medium.
// 2. When the buffer is full: Buffers have a certain size. When the buffer is full it is automatically synchronized.
// 3. Explicitly, with manipulators: When certain manipulators are used on streams, an explicit synchronization takes place. These manipulators are: flush and endl.
// 4. Explicitly, with member function sync(): Calling the stream's member function sync() causes an immediate synchronization. 
//      This function returns an int value equal to -1 if the stream has no associated buffer or in case of failure. 
//      Otherwise (if the stream buffer was successfully synchronized) it returns 0.