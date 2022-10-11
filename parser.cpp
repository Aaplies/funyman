#include <iostream>
#include <string>
#include <vector>

void tester(const char& charToTest, std::vector<char>& nums, std::vector<char>& multiV)
{
    if (isdigit(charToTest) == true)
    {
        nums.push_back(charToTest);
    } else if (charToTest != ',')
    {
        multiV.push_back(charToTest);
    }
}

long parse(const std::string& input)
{
    std::vector <char> nums;
    std::vector <char> multiV;
    int multi;
    std::string num;
    std::string multiS;

    for (int i = 0; i < input.size(); i++)
    {
        tester(input[i], nums, multiV); // sort the letters from the numbers
    }

    for (int i = 0; i < nums.size(); i++)
    {
        num = num + nums[i];
    }

    for (int i = 0; i < multiV.size(); i++)
    {
        multiS = multiS + multiV[i];
    }

    if (multiS == "k")
    {
        multi = 3;
    } else if (multiS == "m")
    {
        multi = 6;
    }
    else if (multiS == "b")
    {
        multi = 9;
    }
    else if (multiS == "t")
    {
        multi = 12;
    }
    else if (multiS == "qa")
    {
        multi = 15;
    }
    else if (multiS == "qi")
    {
        multi = 18;
    }
    else
    {
        multi = 0;
    }

    for (int i = 0; i < multi; i++)
    {
        num = num + "0"; // add the extra 0's
    }

    return std::stol(num);
}
