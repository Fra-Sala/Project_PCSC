//
// Created by francesco on 07/12/22.
//

#ifndef PROJECT_PCSC_MANAGEINPUT_H
#define PROJECT_PCSC_MANAGEINPUT_H

#include <iostream>
#include <string>
#include <fstream>
#include <cassert>
#include <cstring>

//#include <fparser.hh>
#include "AbstractParser.h"
#include "Fparser.h"
#include "ManageInput.h"
#include "ImplicitOdeSolver.h"
#include "AbstractOdeSolver.h"
#include "ForwardEuler.h"
#include "AdamsBashforth.h"
#include "BackwardEuler.h"
#include "ExplicitRungeKutta.h"
#include "BDFSchemes.h"
#include "AdamsMoulton.h"

/*! \class ManageInput
    \brief Class used to manage the input inserted by the user.

    This class allows the user to have plenty of choice on how to use the present
    project to solve an ODE.
*/

class ManageInput {

private:
    int method;                 ///< method selected [1, 6]
    double t0;                  ///< step-size
    double tf;                  ///< final time
    double y0;                  ///< initial value
    double h;                   ///< step-size
    std::string fun;            ///< rhs of the ODE

    int s = 0;                  ///< number of steps (for multisteps methods)

    int stages = 0;             ///< number of stages (for Runge-Kutta methods)

    double nmax;                ///< max number of iterations to solve the non-linear equation (implicit methods only)
    double tol;                 ///< tolerance on the solution of the non-linear equation (implicit methods only)

public:
    //! \brief Customized constructor to initialize the class variables.
    /*!
      This constructor allows the project to be run in three different ways:

      1) The program is only run by ./ProjectOdeSolver and no additional arguments are given: in this case the program will
      guide the user through the program, asking the various parameters that are to be set in order to solve the desired
      ODE;

      2) The program is run by ./ProjectOdeSolver FILE <filename>: in this case the program will look for a file named
      <filename> contained in the directory cmake-build-debug. If no file is found, the program aborts. Otherwise,
      the file is read and parameters are set. Note that the format of the file must be: method fun t0 tf h y0.
      If the method selected is a multistage or multistep method, one additional argument is to be specified, i.e. the
      number of steps or stages. In the end, note also that 'FILE' can also be inserted in lowercase letters, i.e.
      'file';

      3) The program is run by ./ProjectOdeSolver method "fun" to tf h y0: in this case all the arguments are given in the
      command line, so every parameter is set according to this choice. As in the previous case, if a multistep or a
      multistage method is considered, one additional arguments is to be specificed on the command line. Finally, note
      that in this case the variable \param fun should be inserted between quotation marks.

      The arguments taken are the arguments inserted on the command line when the program is run
      (via ./Project_PCSC).
      @param Nargs number of arguments.
      @param args actual arguments contained in a vector of strings.
    */
    ManageInput(int Nargs, char* args[]);

    /** This method sets the solver from the arguments that have been previously set. It takes no input and returns a
     * pointer variable to the solver object created. Additionally, if an implicit method is selected,
     * the program asks the user whether he/she would like to specify a maximum number of iteration and tolerance
     * to solve the non-linear equation. Otherwise, default values for both variables are considered.
     * @return A pointer of type AbstractOdeSolver that points to an object of the specific method selected which
     * has every parameter set according to the previous choice.
    */
    AbstractOdeSolver* ConstructSolver();

};
#endif //PROJECT_PCSC_MANAGEINPUT_H
