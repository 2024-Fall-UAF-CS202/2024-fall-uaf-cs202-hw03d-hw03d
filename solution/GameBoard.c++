#include "GameBoard.h"
#include <sstream>

using Value = GameBoard::Value;

std::ostream& operator<<(std::ostream& out, const Value & v) {
    
    out << std::underlying_type_t<Value>(v);

    return out;
}


std::istream& operator>>(std::istream& in, Value & v) {

    in >> std::noskipws;
    
    char c;
    while (in >> c) {
        if (c != '\n') {
            break;
        }
    }

    switch(c) {
        case 'x':
        case 'X':
            v = Value::Wall;
            break;

        case 'a':
        case 'A':
            v = Value::Player;
            break;

        case 'z':
        case 'Z':
            v = Value::Exit;
            break;

        default:
            v = Value::Empty;
            break;
    }

    return in;

}

std::ostream& operator<<(std::ostream & out, const GameBoard & gameBoard) {

    for (auto & row : gameBoard.data) {

        for (auto & value : row) {

            out << value;

        }

        out << "\n";

    }

    return out;
}

std::vector<std::string> getLines(std::istream & in) {
    
    std::vector<std::string> result;

    std::string line;

    while (std::getline(in, line)) {
        result.push_back(line);
    }

    return result;
}

int maxLength(const std::vector<std::string> & lines) {
    
    auto result = int{0};

    for (auto & line : lines) {
        auto currentLength = line.length();
        if (currentLength > result) {
            result = currentLength;
        }
    }

    return result;
}

std::istream& operator>>(std::istream & in, GameBoard & gameBoard) {
 
    // Get a vector of strings, one string per line in the map file
    const auto lines = getLines(in);
    
    // Figure out what the longest line in the map file was
    const auto numColumns = maxLength(lines);

    // Iterate through each line 
    for (const auto & line : lines) {
        gameBoard.data.push_back(std::vector<Value>(numColumns, GameBoard::Value::Empty));
    }

    // Read the actual values
    for (int row{0}; row < lines.size(); row += 1) {
        
        auto stream = std::istringstream(lines[row]);

        Value v;

        for (int column{0}; stream >> v; column += 1) {

            gameBoard.data[row][column] = v;

        }
    }


    return in;
}
