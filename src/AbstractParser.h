//
// Created by francesco on 01/12/22.
//

#include "fparser.hh"

#ifndef PROJECT_PCSC_ABSTRACTPARSER_H
#define PROJECT_PCSC_ABSTRACTPARSER_H

/*! \class AbstractParser
    \brief Mother abstract class for every function parser.

    This class is Abstract. It allows to use inheritance to easily make use of different function parsers
    without having to re-code whole parts of the program.
*/


class AbstractParser {

protected:
    std::string funString;                  ///< string corresponding to the function that is to be parsed.

public:

    //! A customized constructor.
    /*!
      This customized constructor allows to initialize the string member of the class.
    */
    AbstractParser(std::string fun_rhs);

    //! Default destructor.
    /*!
       Here, the behaviour of such destructor is explicitly set to 'default'. It will be overridden in every
       child class (i.e. for every different function parsing library).
    */
    virtual ~AbstractParser() = default;

    //! Pure virtual method to evaluate the desired function (it will be overridden in each daughter class).
    virtual double EvaluateFun(double t, double y) = 0;

};
#endif //PROJECT_PCSC_ABSTRACTPARSER_H
