//
// Created by francesco on 01/12/22.
//

#include "fparser.hh"

#ifndef PROJECT_PCSC_ABSTRACTPARSER_H
#define PROJECT_PCSC_ABSTRACTPARSER_H

class AbstractParser {

protected:
    std::string funString;

public:
    AbstractParser(std::string fun_rhs);

    //! Default destructor.
    /*!
       Here, the behaviour of such destructor is explicitly set to 'default'. It will be overridden in every
       child class (i.e. for every different function parsing library).
    */
    virtual ~AbstractParser() = default;


    virtual double EvaluateFun(double t, double y) = 0;

};
#endif //PROJECT_PCSC_ABSTRACTPARSER_H
