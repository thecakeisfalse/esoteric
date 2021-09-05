#ifndef _ESOTERIC_HPP_
#define _ESOTERIC_HPP_

#include <iostream>
#include <map>

struct Instruction {
  unsigned char opcode;
  unsigned short operand;
};

void hq9_plus(std::string, std::ostream&);
void brainfuck(std::string, std::ostream&);
void ook(std::string, std::ostream&);
void spoon(std::string, std::ostream&);

bool file_exists(std::string);
std::string read_file(std::string);
bool can_be_converted(std::string);

void arg_help(int, char **);
std::map<std::string, std::string> args_parse(int, char **);

#endif // _ESOTERIC_HPP_
