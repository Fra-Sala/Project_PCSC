//
// Created by francesco on 01/12/22.
//

#include "AbstractParser.h"
#include "fparser.hh"

#ifndef PROJECT_PCSC_FPARSER_H
#define PROJECT_PCSC_FPARSER_H

/*This class allows to parse a function, and to be able to evaluate it
 * from an input string. It inherits from AbstractParser, and uses the library
 * fparser4.5.2 (see http://warp.povusers.org/FunctionParser/fparser.html for documentation
 * of such library). It has a member a pointer to an object FunctionParser, an overriden constructor
 * and a method EvaluateFun, which allows other evaluate the given function. */
class Fparser : public AbstractParser {

private:

    /// This pointer points to the object
    FunctionParser *rhs = new FunctionParser;

public:

    /// The constructor takes as input a std::string "f(t,y)" (e.g: "cos(t)*y"), and sets the member of this class
    /// accordingly.
    Fparser(std::string fun_rhs) : AbstractParser(fun_rhs) {this->rhs->Parse(this->funString, "t,y");}

    /// Destructor
    ~Fparser();

    ///This method uses the method Eval from the library fparser4.5.2 to evaluate a given string like it was a function.
    /// It takes the values of t,y at which the evaluation is required, and return the evaluation as a double.
    /// e.g: double val = EvaluateFun(5.0,3.0);
    double EvaluateFun(double t, double y) override;

};


#endif //PROJECT_PCSC_FPARSER_H
