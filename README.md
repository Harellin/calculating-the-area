# calculating-the-area
a figure bounded by 3 given equations  

This is my university homework.  
Topic: Building multi-module programs. Calculation of the roots of equations and definite integrals.  
Programming language: C, NASM assembler.  

Calculate the area of a flat figure bounded by three curves with a given E absolute accuracy, the equations of which are y = f1(x), y = f2(x) and y = f3(x) are either pre-defined by the task option.  
When solving the problem, the following is necessary:  
  1. With an accuracy of E1, calculate the abscissae of the intersection points of the curves using the method of approximate solution of the equation F(x) = 0 provided for in the assignment option.  
  2. To represent the area of a given figure as an algebraic sum of certain integrals and calculate these integrals with some accuracy E2 according to the quadrature formula provided by the assignment option.  
  3. The values E1 and E2 should be selected independently so that the calculation of the area of the figure with an accuracy of E = 0001 is guaranteed. The choice of values E1 and E2 must have a strict mathematical justification.  
  
My task was:  
  f1 = 0.35 * x^2 + 0.95 * x + 2.7  
  f2 = 3 * x + 1  
  f3 = 1 / (x + 2)  
  
  Method of approximate solution of equations - The method of dividing a segment in half  
  
  Quadrature formula - Simpson's Formula (parabola)  
  
Program requirements:  
  1. Calculating the area  
    -The functions that calculate the values ​​of f1, f2, f3 and their derivatives (if derivatives are necessary) are implemented in assembly language with the cdecl calling convention. All other functions of the program are implemented in the C language.  
    -The calculation with accuracy E1 of the root x of the equation f(x) = g(x) on the interval [a, b] must be implemented in a separate C function root(f, g, a, b, eps1). If the tangent method or the combined method is used, then root must have two more parameters of functional type that allow calling the derivatives of the functions ƒ and d. The root function must not have any other parameters. Calling the calculating values ​​or derivatives of the function by their global names is prohibited.  
    -Calculation with an accuracy of E2 of the value of the definite integral of the function f(x) on the interval [a, b] must be implemented in a separate function integral (f, a, b, eps2) in the C language.  
    -The root and integral C functions must be pre-tested. The main program must provide testing capabilities, activated by a command line option (see below).  
    -The program must be provided with explanatory comments in a volume sufficient for its understanding. All global and static variables must be documented in comments.  
  3. Assembling and testing the program  
    -The program must be built using the make utility. The corresponding file must explicitly or implicitly describe the dependencies between all build targets.  
    -The all and clean targets must be defined, the first of which completely compiles the program, and the second, in particular, object modules.  
    -A test target must be defined that runs the program in root and integral function testing mode with manually selected parameter values. At least three tests must be run for each of them. The tests must include at least three new mathematical functions that can be implemented in C or assembler.  
  
  4. Supported command line options  
  The program must support the following command line switches in long and short form:  
    -The --help and -h options, which print all valid command line switches.  
    -The --root and -r options, which print the abscissas of the intersection points of the curves.  
    -The --iterations and -і options, which print the number of iterations required to approximately solve the equations when searching for intersection points.  
    -The --test-root and -R options, which allow testing the root function. The actual parameters for calling root are specified by the only parameter of this option in the form F1: F2:A:B:E:R, where F1, F2 are the numbers of the functions used, A, B, E are the values ​​of the parameters a, b, eps1 of the root function, R is the correct answer (calculated analytically). The program must call the root function with the specified parameters, compare the result with the correct answer, and display the result, absolute and relative error on the screen.  
    -The --test-integral and -I options, which allow testing the integral function. The actual parameters for calling integral are specified by the only parameter of this option in the form F:A:B:E:R, where F is the number of the function used, A, B, E are the values ​​of the parameters a, b, eps2 of the integral function, R is the correct answer (calculated analytically). The program must call the integral function with the specified parameters, compare the result with the correct answer, and display the result, absolute and relative error on the screen.  
    -The program, launched without input parameters, should output the answer to the given problem (area of ​​the figure).  
