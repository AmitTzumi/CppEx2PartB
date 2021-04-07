#include "Board.hpp"
#include "Board.cpp"
#include "Direction.hpp"
#include <iostream>

using namespace ariel;
int main() {
    Board b;
    b.post(50, 50, Direction::Horizontal, "*");
    for(unsigned long i=1;i<10;i++){
        b.post(50+i, 50-i, Direction::Horizontal, "*");
        b.post(50+i, 50+i, Direction::Horizontal, "*");
    }
    b.post(60,41,Direction::Horizontal, "*******************");
    b.post(61,43,Direction::Horizontal, "House for sale");
    b.post(62,43,Direction::Horizontal, "For details");
    b.post(63,43,Direction::Horizontal, "Please call");
    b.post(64,43,Direction::Horizontal, "This number");
    b.post(65,43,Direction::Horizontal, "0507859677");
    b.post(61,41,Direction::Vertical,"**********");
    b.post(61,59,Direction::Vertical,"**********");
    b.post(71,41,Direction::Horizontal,"*******************");

    //b.post(10, 20, Direction::Horizontal, "abcd");
    //b.post(10, 20, Direction::Vertical, "1234");
    
    b.show();
    return 0;
}
