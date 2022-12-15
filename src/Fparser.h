//
// Created by francesco on 01/12/22.
//

#include "AbstractParser.h"
#include "fparser.hh"

#ifndef PROJECT_PCSC_FPARSER_H
#define PROJECT_PCSC_FPARSER_H

/*! \class Fparser class
    \brief Child class for parsing a string into a function.

     This class allows to parse a function, and to be able to evaluate it
     from an input string. It inherits from AbstractParser, and uses the library
     fparser4.5.2 (see http://warp.povusers.org/FunctionParser/fparser.html for documentation
     of such library). It has a member a pointer to an object FunctionParser, an overriden constructor
     and a method EvaluateFun, which allows other evaluate the given function.
 */
class Fparser : public AbstractParser {

private:
    FunctionParser *rhs;                    //< pointer that points to the object

public:
    //! Customized constructor inherited from AbstractParser.
    /*!
       This constructor takes as input a std::string "f(t,y)" (e.g: "cos(t)*y"), and parses the given string, setting the member
       object pointer rhs (pointer of type FunctionParser) to store the parsing. The given f must be function of t and y.
    */
    Fparser(std::string fun_rhs) : AbstractParser(fun_rhs) {this->rhs = new FunctionParser, this->rhs->Parse(this->funString, "t,y");}

    //! Overridden destructor inherited from AbstractParser.
    /*!
       Frees the memory associated with the member @param rhs.
    */
    ~Fparser() override;

    /*! This method uses the method Eval defined in the library fparser4.5.2 for objects FunctionParser
     * to evaluate a given string and use it as function.
     *
     * @param t value at which the evaluation is required.
     * @param y value at which the evaluation is required.
     * @return the evaluation as a double.
    */
    double EvaluateFun(double t, double y) override;
};

#endif //PROJECT_PCSC_FPARSER_H
