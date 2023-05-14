#include <iostream>
#include <cmath>

int main()
{
    double goal, current, apt, goala, currenta, apta, ticks, seconds, tsp = 0;
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
    seconds = ceil(seconds);
    std::cout << floor(seconds/31536000) << " year(s) ";
    std::cout << int(floor(seconds/86400)) % 365 << " day(s) ";
    std::cout << int(floor(seconds/3600)) % 24 << " hours ";
    std::cout << int(floor(seconds/60)) % 60 << " minutes ";
    std::cout << int(seconds) % 60 << " seconds.";
    return 0;
}
