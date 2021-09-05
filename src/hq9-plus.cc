#include "esoteric.hpp"

void hq9_plus(std::string commands, std::ostream &output) {
    int accumulator = 0;

    for (auto command : commands) {
        if (command == 'H') {
            output << "Hello, world!" << std::endl;
        } else if (command == 'Q') {
            output << commands << std::endl;
        } else if (command == '9') {
            for (int i = 99; i > 1; i--) {
                output << i << " bottles of beer on the wall," << std::endl;
                output << i << " bottles of beer." << std::endl;
                output << "Take one down, pass it around," << std::endl;
                output << i-1 << " bottles of beer on the wall." << std::endl << std::endl;
            }
            output << "1 bottle of beer on the wall," << std::endl;
            output << "1 bottle of beer." << std::endl;
            output << "Take one down, pass it around," << std::endl;
            output << "no more bottles of beer on the wall." << std::endl;
        } else if (command == '+') {
            accumulator++;
        }
    }
}
