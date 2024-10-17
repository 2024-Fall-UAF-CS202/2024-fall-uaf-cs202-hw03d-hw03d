#include "GameBoard.h"  // Provides GameBoard

#include <fstream>      // Provides std::ifstream
#include <iostream>     // Provides std::cout, std::cerr
#include <string>       // Provides std::string
#include <vector>       // Provides std::vector


int main(int argc, char** argv) {
  
  std::cerr << "Sunday is day " << std::underlying_type_t<Day>(Day::Sunday) << "\n";
  return -1;

  // Store command line arguments as C++ vector of C++ strings
  const auto args = std::vector<std::string>{argv, argc + argv};
  
  // Create input file stream to read data from text file
  auto in = std::ifstream(args.at(1));
  
  // Create an empty game board object
  auto data = GameBoard();

  // Attempt to read the data
  in >> data;
  if (in.eof()) {

    // Print the game board
    std::cout << data;

  } else {

    // Something went wrong
    std::cerr << "Failed to read data from " << args.at(1) << "\n";

  }

  std::cerr << "\nGame over\n";
  
  return 0;
}


