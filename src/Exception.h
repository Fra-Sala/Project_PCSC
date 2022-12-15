//
// Created by francesco on 10/12/22.
//

#ifndef PROJECT_PCSC_EXCEPTION_H
#define PROJECT_PCSC_EXCEPTION_H

#include <iostream>

/*! \class Exception
    \brief Generic class for exception to be thrown.

    The class inherits from std::exception. It allows to specify a message
    when an exception is thrown.
*/

class Exception : public std::exception {

private:
    std::string msg;            ///< string containing the message to be printed.

public:

    //! Customized constructor inherited from std::exception.
    /*!
       This constructor takes as input a std::string  and sets the member of the class.
    */
    Exception(const std::string& msg) : msg(msg){}


    /*! This method is overridden from the mother class std::exception. It takes no parameters and returns
     * the string that will be subsequently printed to visualize the message associated with the particular
     * exception.
     * @return the string containing the message.
    */
    virtual const char* what() const noexcept override {
        return msg.c_str();
    }
};
#endif //PROJECT_PCSC_EXCEPTION_H
