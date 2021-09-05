#include "esoteric.hpp"

void spoon(std::string commands, std::ostream &output) {
    std::string brainfuck_commands = "";

    for (size_t i = 0; i < commands.length(); i++) {
        if (commands.substr(i, 1) == "1") {
            brainfuck_commands += "+";
        } else if (commands.substr(i, 3) == "000") {
            brainfuck_commands += "-";
            i += 2;
        } else if (commands.substr(i, 3) == "010") {
            brainfuck_commands += ">";
            i += 2;
        } else if (commands.substr(i, 3) == "011") {
            brainfuck_commands += "<";
            i += 2;
        } else if (commands.substr(i, 5) == "00100") {
            brainfuck_commands += "[";
            i += 4;
        } else if (commands.substr(i, 4) == "0011") {
            brainfuck_commands += "]";
            i += 3;
        } else if (commands.substr(i, 7) == "0010110") {
            brainfuck_commands += ",";
            i += 6;
        } else if (commands.substr(i, 6) == "001010") {
            brainfuck_commands += ".";
            i += 5;
        }
    }

    brainfuck(brainfuck_commands, output);
}
