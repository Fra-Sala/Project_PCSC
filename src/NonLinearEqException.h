//
// Created by francesco on 10/12/22.
//

#include <iostream>
#ifndef PROJECT_PCSC_NONLINEAREQEXCEPTION_H
#define PROJECT_PCSC_NONLINEAREQEXCEPTION_H

class NonLinearEqException : public std::exception {
public:
    const char * what() {
        return "Warning: fixed point iterations are not converging\nSwitching to Broyden algorithm\n";
    }
};
#endif //PROJECT_PCSC_NONLINEAREQEXCEPTION_H
