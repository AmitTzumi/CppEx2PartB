#include "Board.hpp"
#include "Direction.hpp"
#include <string>
#include <iostream>
#include <vector>

using namespace std;
constexpr int DEFAULT_BOARD = 100;
namespace ariel{

    Board::Board(){  // initialazing the board to 100*100 and fill him with "_"
        unsigned long i=0;
        unsigned long j=0;
        len = DEFAULT_BOARD;
        for(i=0;i<len;i++){
            board.push_back(vector<char>());
            for(j=0;j<len;j++){
                board[i].push_back('_');
            }
        }
        //cout << "Board constructor";
    }

    void Board::post(unsigned int row, unsigned int column, Direction dr, string str){
        unsigned long i=0;
        unsigned long cast_row = (unsigned long) row;
        unsigned long cast_column = (unsigned long) column;
        if (cast_row >= board.size() || cast_column >= board[0].size()) { // if the location is out of bounds
            unsigned long new_size=0;
            if (cast_row > cast_column){ // to make it square
                new_size = cast_row + str.size();
            }
            else{
                new_size = cast_column + str.size();
            }
            for (unsigned long i = 0; i < board.size(); i++) { // make space for new columns! with the new size with "_", in this case i just added the remainder
                for (unsigned long j = board[i].size(); j < new_size; j++) {
                    board.at(i).push_back('_');
                }
            }

            for (int i =board.size(); i < new_size; i++) { // make space for the new rows! with the new size with "_", in this case i created a new vector with the new size to show another way
                vector<char> new_row(new_size);
                for (int j=0; j < new_size; j++) {
                    new_row.push_back('_');
                }
                board.push_back(new_row);
            }
            len = (int) new_size; // update the len of the board
        }

        if(dr==ariel::Direction::Horizontal){
            for(i=0;i<str.length();i++){
                board[cast_row][cast_column+i]= str[(unsigned long)i];
            }
        }
        if(dr==ariel::Direction::Vertical){
            for(i=0;i<str.length();i++){
                board[cast_row+i][cast_column]=str[(unsigned long)i];
            }
        }
        //cout << "post func";
    }

    string Board::read(unsigned int row, unsigned int column, Direction dr, unsigned int length){
        unsigned long cast_row = (unsigned long) row;
        unsigned long cast_column = (unsigned long) column;
        string str;
        unsigned long i=0;
        if(dr==ariel::Direction::Horizontal){
            for(i=0;i<length;i++){
                if (board.size() - 1 < cast_row || board[0].size() - 1 < cast_column + i) { // if the location is out of bounds of our board
                    str += "_";
                } else {
                    str += board[cast_row][cast_column+i];
                }
            }
        }
        if(dr==ariel::Direction::Vertical){
            for(i=0;i<length;i++){
                if (board.size() - 1 < cast_row + i || board[0].size() - 1 < cast_column) { // if the location is out of bounds of our board
                    str += "_";
                } else {
                    str += board[cast_row+i][cast_column];
                }
               
            }
        }
        //cout << "read func";
        return str;
    }

    void Board::show(){
        unsigned long i=0;
        unsigned long j=0;
        for(;i<len;i++){
            for(;j<len;j++){
                    cout << board[i][j];
            }
            cout << '\n';
        }
        cout << endl;
    }
}