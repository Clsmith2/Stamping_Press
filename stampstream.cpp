#include "stampstream.h"
#include "stampbuf.h"


stampstream::stampstream(int cols, int rows)
  :std::ostream(new stampbuf(cols, rows))
{ }

stampstream::~stampstream()
{
  delete rdbuf();
}

std::ostream& endrow(std::ostream& os) {
    stampbuf* buf = (stampbuf*)(os.rdbuf());
    if (buf) {
        buf->increment_row();
    }
    return os;
}

std::ostream& operator<<(std::ostream& os, const row& r) {
    stampbuf* buf = (stampbuf*)(os.rdbuf());
    if (buf) {
        int newRow = r.getNewRow(); 
        buf->set_row(newRow);
    }
    return os;
}