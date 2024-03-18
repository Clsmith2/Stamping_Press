#ifndef ROW_H
#define ROW_H

#include <iostream>

class row {
public:
    row(int rowNum) : rowNum(rowNum) {}
    
    int getNewRow() const {  
    return rowNum;
    }

    friend std::ostream& operator<<(std::ostream& os, const row& r);

private:
    int rowNum;
};

#endif