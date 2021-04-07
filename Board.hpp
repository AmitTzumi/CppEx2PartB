#pragma once
#include <string>
#include "Direction.hpp"
#include <vector>
using namespace std;
namespace ariel
{
  class  Board{
      vector<vector<char>> board; // dynamic 2D array, can change his size
      int len;
    public: 
        Board();
        void post(unsigned int row, unsigned int column, Direction dr, string str);
        string read(unsigned int row, unsigned int column, Direction dr, unsigned int length);
        void show(); 
  };
}