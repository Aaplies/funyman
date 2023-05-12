
#include <iostream>
#include <cmath>

int main()
{
    double gp, goal, current, apt, goala, currenta, apta, ticks, seconds, tsp = 0;
    std::cout << "goal & exponent: ";
    std::cin >> goal >> goala;
    std::cout << "current & exponent: ";
    std::cin >> current >> currenta;
    std::cout << "apt & exponent: ";
    std::cin >> apt >> apta;
    std::cout << "zone delay: ";
    std::cin >> tsp;
    ticks = ((goal * pow(10, goala)) - (current * pow(10, currenta)));
    ticks /= (apt * pow(10, apta));
    seconds = ticks * tsp;
    seconds /= 86400;
    std::cout << floor(seconds) << " days ";
    seconds = (seconds - floor(seconds)) * 24;
    std::cout << floor(seconds) << " hours ";
    seconds = (seconds - floor(seconds)) * 60;
    std::cout << floor(seconds) << " minutes ";
    seconds = (seconds - floor(seconds)) * 60;
    std::cout << ceil(seconds) << " seconds.";
}
