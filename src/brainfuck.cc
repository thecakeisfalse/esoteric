#include "esoteric.hpp"
#include <fstream>
#include <vector>

#define MAX_STACK_SIZE 256

void brainfuck(std::string commands, std::ostream &output) {
    int commands_size = commands.length();
    int * stack = new int[MAX_STACK_SIZE];
    int stack_pointer = 0;
    int instructions_size = 0;
    register struct Instruction * instructions = new struct Instruction[commands_size];
    register int index = 0;
    register char current_command;
    char previous_command = 0;
    int count = 0;
    int opened_bracket = 0;
    int buffer[30000] = {0};
    int pointer = 0;
    register int i = 0;

    while (index < commands_size) {
        current_command = commands[index++];
        if (current_command != previous_command) {
            if (previous_command != 0) {
                instructions[instructions_size].opcode = previous_command;
                instructions[instructions_size].operand = count;
                ++instructions_size;
            }

            if (current_command == '+' || current_command == '-' || current_command == '<' || current_command == '>') {
                previous_command = current_command;
                count = 1;
                continue;
            } else {
                previous_command = 0;
                count = 0;
            }
        } else {
            ++count;
        }

        if (current_command == '[') {
            instructions[instructions_size].opcode = current_command;
            if (stack_pointer >= MAX_STACK_SIZE) {
                // TODO - resize stack on overflow
                std::cerr << "Error: too much opened brackets" << std::endl;

                delete[] stack;
                delete[] instructions;

                exit(1);
            }
            stack[stack_pointer++] = instructions_size;
            ++instructions_size;
        } else if (current_command == ']') {
            --stack_pointer;
            opened_bracket = stack[stack_pointer];
            instructions[instructions_size].opcode = current_command;
            instructions[instructions_size].operand = opened_bracket;
            instructions[opened_bracket].operand = instructions_size;
            ++instructions_size;
        } else if (current_command == '.' || current_command == ',') {
            instructions[instructions_size].opcode = current_command;
            instructions[instructions_size].operand = 0;
            ++instructions_size;
        }
    }

    while (i < instructions_size) {
        switch (instructions[i].opcode) {
            case '+':
                buffer[pointer] += instructions[i].operand;
                break;
            case '-':
                buffer[pointer] -= instructions[i].operand;
                break;
            case '<':
                pointer -= instructions[i].operand;
                break;
            case '>':
                pointer += instructions[i].operand;
                break;
            case '[':
                if (buffer[pointer] == 0) {
                    i = instructions[i].operand;
                }
                break;
            case ']':
                if (buffer[pointer] != 0) {
                    i = instructions[i].operand;
                }
                break;
            case '.':
                output << (char)buffer[pointer];
                break;
            case ',':
                buffer[pointer] = std::cin.get();
                break;
        }
        ++i;
    }

    delete[] instructions;
    delete[] stack;
}
