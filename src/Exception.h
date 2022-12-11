//
// Created by francesco on 10/12/22.
//

#include <iostream>
#ifndef PROJECT_PCSC_EXCEPTION_H
#define PROJECT_PCSC_EXCEPTION_H

/* This is a generic class for exception to be thrown.
 * It inherits from std::exception. It allows to specify a message
 * when an expection is thrown. */
class Exception : public std::exception
{
    std::string msg;
public:
    Exception(const std::string& msg) : msg(msg){}

    virtual const char* what() const noexcept override
    {
        return msg.c_str();
    }
};
#endif //PROJECT_PCSC_EXCEPTION_H
