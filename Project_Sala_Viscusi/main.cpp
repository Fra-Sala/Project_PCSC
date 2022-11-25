#include <iostream>
#include <fstream>
#include "fparser.hh"

int main(int argc, char* argv[]) {

    // The code must be called specyfing a function

    if (argc > 1) {

        std::cout << "we are gonna use a file" << std::endl;
    } else
    {
        std::cout << "we are gonna use the screen to print the solution" << std::endl;
    }


    FunctionParser *fp_RHS;

    fp_RHS->Parse(argv[1], "t,y");
    double v[2] = {
            ,1};
    double result = fp_RHS->Eval(v);

    std::cout << result << std::endl;
    return 0;
}
