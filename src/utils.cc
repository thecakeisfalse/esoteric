#include <iostream>
#include <sys/stat.h>
#include <cstdio>

bool file_exists(std::string filename) {
    struct stat st;
    return stat(filename.c_str(), &st) == 0 && S_ISREG(st.st_mode);
}

std::string read_file(std::string filename) {
    char buffer[1024*1024];
    FILE * file = fopen(filename.c_str(), "r");
    int length = fread(buffer, 1, 1024 * 1024, file);
    buffer[length] = 0;
    fclose(file);
    return std::string(buffer);
}

int get_file_size(std::string filename) {
    struct stat st;
    stat(filename.c_str(), &st);
    return st.st_size;
}
