# Programming Concepts in Scientific Computing Project
## Table of contents
* [Project Description](#Description)
* [Installation of the repository](#Installation)
* [Producing documentation](#Documentation)
* [Parameters](#Parameters)
* [Specifying the parameters](#ParametersSpecification)
* [About the implicit methods](#Implicit)
* [About the visualization of the solution](#Visualization)

## Project Description
This C++ project aims at solving the Cauchy problem for 1st order Ordinary Differential Equations (ODE) in the form:

		$$y'=f(t, y) \\$$
		$$y(0) = y_0 \\$$
		$$t \in [t_0, t_f] \\$

The user can select one of the following list of ODE solvers:
$\begin{enumerate}
	\item Forward Euler
	\item Adams-Bashforth multistep method (1 to 4 steps)
	\item Backward Euler
	\item Explicit Runge-Kutta (1 to 4 stages)
	\item Backward Differentiation Formula (BDF) (1 to 3 steps)
	\item Adams-Moulton multistep methods (1 to 4 steps)
   \end{enumerate}$
   
###########################################################################################################################
######################## DON'T KNOW IF WE SHOULD KEEP THIS OR NOT 
############################################################################################################################
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
############################################################################################################################


## Installation of the repository
To use the code, please open a terminal, go to your desired directory and clone this repository (make sure that [GIT](https://git-scm.com/) is installed on your device). You can use the HTTPS URL as follow: 
```
git clone https://github.com/Fra-Sala/Project_PCSC.git
```
once the repository has been cloned, to run the code please open a terminal in the repository cloned, select the directory cmake-build-debug as follow:
```
cd cmake-build-debug
```
At this point, the executable (Project_PCSC) may be run in three different ways, as explained in Parameters section.


## To produce documentation 
In order to produce the documentation of the project, please make sure that [Doxygen](https://www.doxygen.nl/) is installed on your machine. If not, open a terminal and type (for *Ubuntu*):
```
sudo apt-get update
sudo apt-get install doxygen
```
once *Doxygen* is installed, documentation can be generated either by typing
```
doxygen
```
in a terminal window in the project repository (this will cause all the target files to be scanned in order to produce documentation), or by installing [Doxywizard](https://doxygen.nl/manual/doxywizard_usage.html). In the latter case, open a terminal and type:
```
sudo apt-get install doxygen-gui
```
Thus, *Doxywizard* can be run as follows:
```
doxywizard
```
In the window that will appear it will be possible to specify the working directory from which *Doxygen* will run and the directory where *Doxygen* will put the generated documentation. Once the process is completed, two new directories will be visible:

* html;
* latex.

  
## Parameters
In order to define the Cauchy problem and the desired solver, the user must provide:

* a chosen ODE solver;
* the function f(t,y);
* the value of t0 (initial time);
* the value of tf (final time);
* initial value for the solution y0;
* stepsize h for domain discretization (the solution will be evaluated at t_i = t0+h*i, i = 1, ..., N, N = (tf-t0)/h);
* the number of steps/stages (depending on the solver chosen);
* if wanted, the user can change the default value of tolerance between two subsequent iterations (tol) and maximum number of iterations (nmax) for the implicit methods (which require the use of nonlinear equation solvers, which are stopped by either tol or nmax).
	
	
## Specifying the parameters
The parameters of the problem of interest can be specified in 3 different ways:

1) As asked by the program: if the user runs only the executable (e.g: ./Project_PCSC), the program itself will ask 
		            what kind of solver one would like to use (which is selected by specifying the corrisponding number),
		            the function f(t,y), t0, tf, h, y0. If the user selects a method that depends on the number of steps/stages
		            this information will be asked by the program. If the user selects an implicit method, the program asks whether 
		            the user wants to use a value for tol and nmax different from the default values (default values: tol = 1e-8, nmax = 1000).

2) As specified from command line: the user can run the executable specifying from command line all the required parameters. A format for the call would be:
				   ./Project_PCSC method "f(t,y)" t0 tf y0 h steps/stages tol nmax
				   where method is an integer from 1 to 6 as listes above, steps/stages are required only for method 2,4,5,6, tol and nmax can be omitted. Note the quotation marks on f(t, y).
				   
3) As specified from file: the user can run the executable as follows:
				./Project_PCSC file "name_of_file.txt", where 
				name_of_file.txt is a text file formatted as follows:
				
				--------- in "name_of_file.txt" --------------
				method f(t,y) t0 tf y0 h steps/stages tol nmax
				----------------------------------------------
				(here the dashes are used only for highlighting purposes and are not to be 
				included in the file).
				Once again, method is an integer from 1 to 6 as listes above, steps/stages 
				are required only for method 2,4,5,6, tol and nmax can be omitted.

Evidently, the most user-friendly option is the 1st one presented.


## About the implicit methods
Implicit methods require, at each timestep, the solution of a nonlinear equation $g(x) = 0$. 
To solve such equations, two algorithms were implemented: fixed point iterations, and Broyden method (quasi-Newton method).
Both methods are iterative, which means that a stopping criteria must be chosen. In this project, both algorithm are stopped when either the number of iterations equals nmax (by default, nmax = 1000) or when the difference between two values of x is smaller, in absolute value, than a given tolerance tol (by default, tol = 1e-8). The ODE solver tries first the fixed point iteration algorithm; if it fails to converge, the program switches to Broyden method. In this case an exception is thrown, and a warning is printed to let the user know about this behaviour.


## About the visualization of the solution
The user can decide to visualize the solution of the ODE in two ways:

* let the program print the solution to the screen (two columns format);
* let the program produce a [MATLAB](https://www.mathworks.com/products/matlab.html) file, where the solution is plotted and visualized. In this case, make sure *MATLAB* is installed on your device.


















