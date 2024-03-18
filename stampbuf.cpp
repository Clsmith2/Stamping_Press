#include "stampbuf.h"
#include "stamp.h"
#include "stampstream.h"


stampbuf::stampbuf(int cols, int rows) : cols(cols), rows(rows), buffer(new char[cols]), curCol(0), curRow(0) {
    setp(buffer, buffer + cols-1);
    stamping_press::insert_plate(cols, rows);
}

stampbuf::~stampbuf() {
    sync();
    stamping_press::eject_plate();
    delete[] buffer;
}

int stampbuf::overflow(int c) {
    *pptr() = c;
    pbump(1);
    sync();
    return c;
}
int stampbuf::sync() {
    if(curRow < 0){
        setp(pbase(), epptr());
        return 0;
    }
    
    char* cp = pbase();
    while (cp!=pptr()) {
        try{
            if (*cp == stamping_press::get_die()) {
                stamping_press::stamp(curCol, curRow);
            }
            else{
            stamping_press::set_die(*cp);
            stamping_press::stamp(curCol, curRow);
            }
        }
        catch(...){}
        ++cp; 
        curCol++;
    }
    setp(pbase(), epptr());
    return 0;
}
void stampbuf::increment_row(){
    sync();
    curRow++;
    curCol = 0;
 }

 void stampbuf::set_row(int row){
    sync();
    curRow = row;
    curCol = 0;
 }

