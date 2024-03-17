#include <stdio.h>
using namespace std;

inline char ReadChar() {
    static char readbuffer[500024];
    static int buf_p, buf_l; // retain values across function calls

    printf("%d %d", buf_p, buf_l);

    // buffer pointer 'buf_p' has reached the buffer length 'buf_l'. 
    // If equal, it means that the buffer is empty, and it reads a new block of characters into
    // 'readbuffer' from stdin using 'fread'.
    if (buf_p == buf_l) {
        buf_l = (int) fread(readbuffer, 1, 500024, stdin);
        buf_p = 0;
    }

    return readbuffer[++buf_p];
}

inline void ReadInt(int& r) {
    r = 0;
    bool bMinus = false;
    char now = ReadChar();

    while (!(now >= '0' && now <= '9') && now != '-')
        now = ReadChar();
    
    if (now == '-') {
        bMinus = true;
        now = ReadChar();
    }

    while (now != '\n' && now != ' ') {
        r *= 10;
        r += now - '0';
        now = ReadChar();
    }
    if (bMinus) r*= -1;
}

int main() {
    ReadChar();
    ReadInt();
}