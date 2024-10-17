#include <iostream>
#include <vector>
/* 
enum class Day {
    Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday
};
*/

class GameBoard {

public:

    // GameBoard::Value represents the value stored
    //    at a location on the GameBoard
    //
    // These values have an **underlying representation** of type char
    enum class Value : char {
        Empty  = ' ', 
        Wall   = 'X', 
        Player = 'A', 
        Exit   = 'Z'
    };

    friend std::istream& operator>>(std::istream& in, GameBoard & data);

private:

    std::vector<std::vector<Value>> data;
};

std::ostream& operator<<(std::ostream& out, const GameBoard::Value & v);
std::istream& operator>>(std::istream& in,        GameBoard::Value & v);

std::ostream& operator<<(std::ostream& out, const GameBoard & data);
std::istream& operator>>(std::istream& in,        GameBoard & data);
