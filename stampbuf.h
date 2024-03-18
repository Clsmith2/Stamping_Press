#ifndef STAMPBUF_H
#define STAMPBUF_H
#include <iostream>
#include "stamp.h"
#include "stampstream.h"

class stampstream;

class stampbuf : public std::streambuf {
    public:
        int sync();
        int overflow(int c);
        void increment_row();
        void set_row(int row);
        void resizeBuffer();
        stampbuf(int cols, int rows);
        ~stampbuf();
    private:
        int curCol;
        int curRow;
        int cols;
        int rows;
        char* buffer;
        int bufferSize;
};

#endif