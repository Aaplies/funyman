#include <iostream>
#include <vector>
#include <string>

float decimalParse(const std::string& input)
{
    std::vector <char> nums;
    std::vector <char> suffix;
    std::string suffixString;
    int multi = 0;
    bool decimalPoint = false;
    float num;
    std::string numS;

    for (int i = 0; i < input.size(); i++)
    {
        if (isdigit(input[i]) == true)
        {  
            nums.push_back(input[i]);
        }
        else if (input[i] != ',' && input[i] != '.') // make sure it's not a comma or decimal, just a suffix
        {
            suffix.push_back(input[i]);
        }
        else if (input[i] == '.') // decimal gets it's own else if; comma gets ignored
        {
            decimalPoint = true;
            nums.push_back(input[i]);
        }
    }

    for (int i = 0; i < nums.size(); i++)
    {
        numS = numS + nums[i];
    }

    num = std::stof(numS);

    for (int i = 0; i < suffix.size(); i++)
    {
        suffixString = suffixString + suffix[i];
    }

    if (suffixString == "k")
    {
        multi = 3; // number of 0's to add
    }
    else if (suffixString == "m")
    {
        multi = 6;
    }
    else if (suffixString == "b")
    {
        multi = 9;
    }
    else if (suffixString == "t")
    {
        multi = 12;
    }
    else if (suffixString == "qa")
    {
        multi = 15;
    }

    for (int i = 0; i < multi; i++)
    {
        num *= 10; // adds the 0's by multiplying num by 10
    }

    return num;
}

int main()
{
    std::string input;
    std::cout << "Input a number: ";
    std::cin >> input;

    std::cout << decimalParse(input) << std::endl;
    return 0;
}
