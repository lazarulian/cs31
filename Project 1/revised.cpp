// Apurva Shah: CS 31 Project 1

#include <iostream>
int main()
{
double r, r_squared, test;
std::cout << "what is the value for r ?\n";
std::cin >> r;
r_squared = r * r;
std::cout << "r-squared = " << r_squared << std::endl;
double vif = 1 / (1 - r_squared);
std::cout << "vif = " << vif << std::endl;
test = 1 - vif;
std::cout << "test = " << test << std::endl;
if (vif > 1) {
std::cout << "vif is greater than 1"; }
else {
std::cout << "vif is less than 1"; }
return 0; }
