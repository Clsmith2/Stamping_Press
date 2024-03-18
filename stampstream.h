#ifndef STAMPSTREAM_H
#define STAMPSTREAM_H
#include <iostream>
#include "stampbuf.h"
#include "stamp.h"
#include "endrow.h"
#include "row.h"


class stampstream : public std::ostream {
    public:
        stampstream(int cols, int rows);
        ~stampstream();
};
#endif