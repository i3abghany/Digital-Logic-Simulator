#include <iostream>

#include "Simulator.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
	  std::cout << "Please provide an input file." << std::endl;
	  exit(EXIT_FAILURE);
    }

    Simulator s;
    auto fN = std::string(argv[1]);
   // auto fN = "test.cir";
    s.load(fN);
    return EXIT_SUCCESS;
}
