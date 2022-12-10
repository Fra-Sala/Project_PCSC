This is a template project structure for the *Programming concepts in scientific computing* (MATH-458)

In order to compile it you should first install *googletest*

```
git submodule update --init 
```

Then, building is done as usual, e.g. with CLion or in the terminal:

```
mkdir build
cd build
cmake ..
make
```
############################################################################
####################"Project: ODE solver y'(t,y) = f(t,y)"##################

This C++ project aims at solving the Cauchy problem for 1st order Ordinary Differential Equations (ODE) in the form:

		y'=f(t,y)
		y(0) = y0
		t \in [t0, tf]

The user can select one of the following list of ODE solvers:

1) Forward Euler
2) Adams-Bashforth multistep method (1 to 4 steps)
3) Backward Euler
4) Explicit Runge-Kutta             (1 to 4 stages)
5) Backward Differantiation Formula (BDF) (1 to 3 steps)
6) Adams-Moulton multistep methods  (1 to 4 steps)
  
############################### PARAMETERS ##################################
In order to define the Cauchy problem and the desidered solver, the user must provide:

-> a chosen ODE solver
-> the function f(t,y)
-> the value of t0 (initial time)
-> the value of tf (final time)
-> initial value for the solution y0
-> stepsize h for domain discretization (the solution will be evaluated at t_i = t0+h*i, i = 1, ..., N, N = (tf-t0)/h)
-> the number of steps/stages (depending on the chosen solver)
-> if wanted, the user can change the default value of tolerance between two subsequent iterations (tol) and maximum number of iterations (nmax) for the implicit methods 
	(which require the use of nonlinear equation solvers, which are stopped by either tol or nmax)
	
##################### SPECIFYING THE PARAMETERS ##############################
The parameters of the problem of interest can be specified in 3 different ways:

1) As asked by the program: if the user runs only the executable (e.g: ./Project_PCSC), the program itself will ask 
		            what kind of solver one would like to use (which is selected by specifying the corrisponding number),
		            the function f(t,y), t0, tf, h, y0. If the user selects a method that depends on the number of steps/stages
		            this information will be asked by the program. If the user selects an implicit method, the program asks whether 
		            the user wants to use a value for tol and nmax different from the default values (default values: tol = 1e-8, nmax = 1000).

2) As specified from command line: the user can run the executable specifying from command line all the required parameters. A format for the call would be:
				   ./Project_PCSC method "f(t,y)" t0 tf y0 h steps/stages tol nmax
				   where method is an integer from 1 to 6 as listes above, steps/stages are required only for method 2,4,5,6, tol and nmax can be omitted.
				   
3) As specified from file: the user can run the executable as follows:
				./Project_PCSC file "name_of_file.txt" , where name_of_file.txt is a text file formatted as follows:
				
				--------- in "name_of_file.txt" --------------
				method f(t,y) t0 tf y0 h steps/stages tol nmax
				----------------------------------------------
				(here the dashes are used only for highlighting purposes and are not to be included in the file).
				Once again, method is an integer from 1 to 6 as listes above, steps/stages are required only for method 2,4,5,6, tol and nmax can be omitted.

Evidently, the most user-friendly option is the 1st one presented.

########################### ABOUT THE IMPLICIT METHOD ################################
Implicit methods require, at each timestep, the solution of a nonlinear equation g(x) = 0. 
To solve such equations, two algorithms were implemented: fixed point iterations, and Broyden method (quasi-Newton method).
Both methods are iterative, which means that a stopping criteria must be chosen. In this project, both algorithm are stopped when
either the number of iterations equals nmax (by default, nmax = 1000) or when the difference between two values of x is smaller, 
in absolute value, than a given tolerance tol (by default, tol = 1e-8). The ODE solver tries first the fixed point iteration algorithm;
if it fails to converge, the program switches to Broyden method. In this case an exception is thrown, and a warning is printed to let the user
know about this behaviour.

####################### ABOUT VISUALIZATION OF THE SOLUTION ###########################

				   


















