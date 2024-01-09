#include"iterative_methods.h" 
#include<tuple> 
#include<iostream> 
#include<cmath> 
#include <iomanip>

//this is me trying to run some tests to see if my stuff works, please ignore

int main(){
    // Test function for fixed point iteration
  auto f1 = [](double x) { return 0.1*(x*x-4); };

  // Run fixed point iteration
  auto result1 = fixed_point_iteration(f1, 0.4, 1e-6);

  // Check if the result is correct
  double root1 = 2.0;
  if (std::get<0>(result1) == true &&
      std::abs(std::get<1>(result1) - root1) < 1e-6) {
    std::cout << "Fixed point: PASS\n";
  } else {
    std::cout << "Fixed point: FAIL, root is " << std::setprecision(10)
              << std::get<1>(result1) << ", expected to be around " << root1
              << std::endl;
  }
   // Test function for bisection
  auto f2 = [](double x) { return x*x*x - 2*x*x + 4; };

  // Run bisection
  auto result2 = bisection(f2, -2.0, 0, 1e-6);

  // Check if the result is correct
  double root2 = -1.13;
  if (std::get<0>(result2) == true &&
      std::abs(std::get<1>(result2) - root2) < 1e-6) {
    std::cout << "Bisection: PASS\n";
  } else {
    std::cout << "Bisection: FAIL, root is " << std::setprecision(10)
              << std::get<1>(result2) << ", expected to be around " << root2
              << std::endl;
  }
    // Test function and derivative for Newton-Raphson
  auto f3 = [](double x) { return x*x - 2; };
  auto f3prime = [](double x) { return 2*x; };

  // Run Newton-Raphson
  auto result3 = newton_raphson(f3, f3prime, 2.0, 1e-6);

  // Check if the result is correct
  double root3 = 1.414;
  if (std::get<0>(result3) == true &&
      std::abs(std::get<1>(result3) - root3) < 1e-6) {
    std::cout << "Newton: PASS\n";
  } else {
    std::cout << "Newton: FAIL, root is " << std::setprecision(10)
              << std::get<1>(result3) << ", expected to be around " << root3
              << std::endl;
  }

  return 0;
  }
