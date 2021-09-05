#include "esoteric.hpp"
#include <iostream>

void ook(std::string commands, std::ostream &output) {
    std::string only_special_commands = "";
    std::string brainfuck_commands = "";
    std::string command = "";

    for (auto el : commands) {
        if (el == '!' || el == '.' || el == '?') {
            only_special_commands += el;
        }
    }

    for (size_t i = 0; i < only_special_commands.length(); i += 2) {
        command = only_special_commands.substr(i, 2);
        if (command == "..") {
            brainfuck_commands += "+";
        } else if (command == ".?") {
            brainfuck_commands += ">";
        } else if (command == ".!") {
            brainfuck_commands += ",";
        } else if (command == "?.") {
            brainfuck_commands += "<";
        } else if (command == "?!") {
            brainfuck_commands += "]";
        } else if (command == "!.") {
            brainfuck_commands += ".";
        } else if (command == "!?") {
            brainfuck_commands += "[";
        } else if (command == "!!") {
            brainfuck_commands += "-";
        }
    }

    brainfuck(brainfuck_commands, output);
}
