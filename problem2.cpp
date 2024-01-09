#include"iterative_methods.h"
#include<iostream> 
#include<cmath> 
#include<fstream>


int main(){
    double m1 = 1.988e30; 
    double m2 = 5.9722e24; 
    double mu = m2/(m1+m2);  
    auto f1 = [mu](double x1) { return (1-mu)/std::pow((1-x1), 2) - mu/std::pow(x1, 2) -1 +mu + x1; }; 
    //choosing bisection as the method 
    auto result1 = bisection(f1, 0, 1, 1e-4);  
    std::ofstream outputFile("problem2.txt"); 
    //prints result and writes it into output file 
    std::cout << "r1: " << std::get<1>(result1)<< "R"<< std::endl; 
    outputFile << "r1: " << std::get<1>(result1)<< "R"<< std::endl; 
    auto f2 = [mu](double x2) {return (1-mu)/std::pow((1+x2),2) + mu/(x2*x2) - x2 - 1 +mu;  }; 
    auto result2 = bisection(f2, 0, 1, 1e-4); 
    std::cout << "r2: " << std::get<1>(result2) << "R" << std::endl; 
    outputFile<< "r2: " << std::get<1>(result2) << "R" << std::endl; 
   auto f3 = [mu](double x2){return (1-mu)/std::pow((1-x2), 2)+ mu/std::pow((2-x2),2) + x2- mu -1; }; 
   auto result3 = bisection(f3, 0, 1, 1e-7); 
   std::cout << "r3: " << std::get<1>(result3) << "R" << std::endl; 
   outputFile << "r3: " << std::get<1>(result3) << "R" << std::endl; 
}
