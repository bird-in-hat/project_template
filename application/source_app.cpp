#include "include\header_app.h"

#include <stdlib.h>
#include <stdio.h>
#include <string>

int main(int argc, const char** argv) {
    ClassName app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}