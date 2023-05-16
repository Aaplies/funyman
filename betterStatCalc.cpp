#include <iostream>
#include <cmath>

int main()
{
    double goal, current, apt, goala, currenta, apta, ticks, seconds, tsp = 0;
    std::cout << "Goal & Exponent: ";
    std::cin >> goal >> goala;
    std::cout << "Current & Exponent: ";
    std::cin >> current >> currenta;
    std::cout << "APT & Exponent: ";
    std::cin >> apt >> apta;
    std::cout << "Zone Delay: ";
    std::cin >> tsp;
    if (goal == -1)
    {
        seconds = 0;
        std::cout << "Custom seconds input: ";
        std::cin >> seconds;
        std::cout << "Goal & Exponent: ";
        std::cin >> goal >> goala;
    }
    if (goal <= 0 || apt <= 0 || goala < 0 || currenta < 0 || goala < 0 || apta < 0)
    {
        std::cout << "Error with 0's in input.\n";
        return 1;
    }
    ticks = ((goal * pow(10, goala)) - (current * pow(10, currenta)));
    ticks /= (apt * pow(10, apta));
    ticks *= tsp;
    seconds += ticks;
    seconds = ceil(seconds);
    std::cout << floor(seconds/31536000) << " year(s) ";
    std::cout << int(floor(seconds/86400)) % 365 << " day(s) ";
    std::cout << int(floor(seconds/3600)) % 24 << " hours ";
    std::cout << int(floor(seconds/60)) % 60 << " minutes ";
    std::cout << int(seconds) % 60 << " seconds.\n\n";
    std::cout << seconds << " total seconds.\n";
    return 0;
}
