#include <iostream>

int main()
{  
    int hours = 0;
    int minutes = 0;
    int tpm;

    std::cout << "Hours: ";
    std::cin >> hours;
   
    std::cout << "Minutes: ";
    std::cin >> minutes;
   
    std::cout << "TPM: ";        
    std::cin >> tpm;

    int totalMinutes = (hours * 60) + minutes;

    int current = 0;

    int i = 0;

    bool includeTpmGain = true; // change this to false for classic
    
    while (i < totalMinutes)
    {
        current = current + tpm;
        if (i % 240 == 239 && includeTpmGain == true)
        {
            tpm++;
        }
        i++;
    }

    std::cout << "You will get " << current << " tokens." << std::endl;

    return 0;
}
