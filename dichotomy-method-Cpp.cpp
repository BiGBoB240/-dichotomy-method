#define _USE_MATH_DEFINES
#include <iostream>  
#include <iomanip>  
#include <cmath>  
 
double func(double x) { 
    return "Your example";
} 
 
double f(double x) { 
    return func(x); 
} 
 
double bisection(double a, double b, double tolerance) { 
    double c; 
    int iterations = 1; 
    while ((b - a) >= tolerance) { 
        std::cout << "Ітерація " << iterations << ": [a, b] = [" << std::fixed << std::setprecision(6) << a << ", " << b << "]" << std::endl; 
        c = (a + b) / 2; 
        std::cout << "c = (a + b) / 2 = " << std::fixed << std::setprecision(6) << c << std::endl; 
        double fa = f(a); 
        double fc = f(c); 
        double product = fa * fc; 
        std::cout << "F(a) = " << std::fixed << std::setprecision(6) << "2 * sin(" << a << ") * cos2(" << a << ") =" << fa << "\nF(c) = " << std::fixed << std::setprecision(6) << "2 * sin(" << c << ") * cos2(" << c << ") =" << fc << "\nF(a) * F(c) = " << fa << " * " << fc << " = " << std::fixed << std::setprecision(6) << product << std::endl << std::endl; 
 
        double diff = b - a; 
        std::cout << "B - A = " << a << " - " << b << " = " << std::fixed << std::setprecision(6) << diff; 
        if (diff > tolerance) { 
            std::cout << " > " << std::fixed << std::setprecision(6) << tolerance << std::endl; 
        } 
        else if (diff < -tolerance) { 
            std::cout << " < " << std::fixed << std::setprecision(6) << tolerance << std::endl; 
        } 
        else { 
            std::cout << " ≈ " << std::fixed << std::setprecision(6) << tolerance << std::endl; 
        } 
 
        if (product == 0.0) { 
            break;
        } 
        if (product < 0) { 
            b = c; 
            std::cout << "B=C = " << std::fixed << std::setprecision(6) << b << std::endl; 
        } 
        else { 
            a = c; 
            std::cout << "A=C = " << std::fixed << std::setprecision(6) << a << std::endl; 
        } 
        iterations++; 
        std::cout << std::endl;
    } 
    return c; 
} 
 
int main() { 
    double a = 0; 
    double b = 0; 
    double tolerance = 0.001; 
	cin << a << b << tolerance;
 
    double root = bisection(a, b, tolerance); 
 
    std::cout << "Your X eval : " << std::fixed << std::setprecision(6) << root << "; With tolerance :"  << tolerance << std::endl; 
 
    return 0; 
}