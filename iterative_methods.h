#pragma once

#include <cmath>
#include <iostream>
#include <tuple>

template <typename F>
std::tuple<bool, double> fixed_point_iteration(const F &f, double x0,
                                               double tolerance) {
  double x = x0;
  int i = 0;
  int i_max = 100;
  while (std::abs(f(x)) > tolerance) {
    // the right hand side of fixed-point iteration can be formed as x - f(x)
    x = x - f(x);
    i += 1;
    if (i > i_max) {
      // If the iteration doesn't converge within maximum number of iterations,
      // return false
      return std::make_tuple(false, x);
    }
  }
  return std::make_tuple(true, x);
}

template <typename F>
std::tuple<bool, double> bisection(const F &f, double a, double b,
                                   double tolerance) {
  double fa = f(a);
  double fb = f(b);
  // Check whether f(a) and f(b) have opposite signs (i.e. whether the root is
  // bracketed)
  if (fa * fb > 0) {
    return std::make_tuple(false, 0.0);
  }
  // c is the midpoint of the interval [a, b]
  double c = (a + b) / 2.0;
  // evaluate f(c). We need to check whether it's close to zero
  double fc = f(c);
  while (std::abs(fc) > tolerance) {
    // if f(a) and f(c) are opposite sign, then replace b with c; otherwise
    // replace a with c
    if (fa * fc < 0) {
      b = c;
    } else {
      a = c;
    }
    // Update the midpoint
    c = (a + b) / 2.0;
    fc = f(c);
  }
  return std::make_tuple(true, c);
}

template <typename F, typename Fprime>
std::tuple<bool, double> newton_raphson(const F &f, const Fprime &fprime,
                                        double x0, double tolerance) {
  double x = x0;
  int i = 0;
  int i_max = 100;
  while (std::abs(f(x)) > tolerance) {
    // Newton-Raphson iteration
    x = x - f(x) / fprime(x);
    i += 1;
    if (i > i_max) {
      // If the iteration doesn't converge within maximum number of iterations,
      // return false
      return std::make_tuple(false, x);
    }
  }
  return std::make_tuple(true, x);
}