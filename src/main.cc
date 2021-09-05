#include "esoteric.hpp"
#include <fstream>

int main(int argc, char * argv[]) {
    std::map<std::string, std::string> args = args_parse(argc, argv);

    std::string source;
    if (args["input_filename"] == "" || !file_exists(args["input_filename"])) {
        std::cout << argv[0] << ": no input files" << std::endl;
        return 2;
    } else {
        source = read_file(args["input_filename"]);
    }

    std::ofstream fout;
    bool custom_output = false;
    if (args["output_filename"] != "stdout") {
        fout.open(args["output_filename"].c_str());
        custom_output = true;
    }

    if (args["language"] == "hq9+") {
        hq9_plus(source, (custom_output ? fout : std::cout));
    } else if (args["language"] == "brainfuck") {
        brainfuck(source, (custom_output ? fout : std::cout));
    } else if (args["language"] == "ook") {
        ook(source, (custom_output ? fout : std::cout));
    } else if (args["language"] == "spoon") {
        spoon(source, (custom_output ? fout : std::cout));
    }
    return 0;
}
