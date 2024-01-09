#include<tuple> 
#include<iostream> 
#include<cmath> 
#ifndef ADD_H_INCLUDED
#define ADD_H_INCLUDED

template <typename F>
std::tuple<bool, double> fixed_point_iteration(const F& f, double x0, double tolerance){
    double x = x0;
	//note that this ignores the situation where abs(g'(x) >1), this function doesn't expressely check g'(x) 
		for(int i = 0; i <= 1000; i++){
				double x_next = x - f(x); 
				if(std::abs(x_next-x) < tolerance){ 
						return std::make_tuple(true, x);
				}
				x = x_next; 
		}
return std::make_tuple(false,x); 
}

template <typename F>
std::tuple<bool, double> bisection(const F& f, double a, double b, double tolerance){
    if(f(a)*f(b) > 0){
		return std::make_tuple(false, 0.0);
	} else {
		for(int i = 0; i <= 1000; i++){
			double x_next = (a+b)/2.0; 
			if((b-a)<tolerance){
				return std::make_tuple(true, x_next); 
			} else {
				if((f(a) * f(x_next))< 0){
					b= x_next;
				}
				if((f(b)* f(x_next))< 0){
					a=x_next; 
				}
			}
		}
		return std::make_tuple(false, 0.0);
	}
}

template <typename F, typename Fprime>
std::tuple<bool, double> newton_raphson(const F& f, const Fprime& fprime, double x0, double tolerance){
    double x = x0; 
		for(int i = 0; i < 1000; i++){
				double x_next = x - f(x)/fprime(x); 
				if(std::abs(x-x_next)< tolerance){
						return std::make_tuple(true, x);
				}
				x = x_next; 
		}
		return std::make_tuple(false,x); 
}
#endif