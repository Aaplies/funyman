// Code may be outdated.
// see the most recent version at https://github.com/Aaplies/funyman/blob/main/tokenmaximizer.cpp
#include <iostream>
#include <vector>
#include <cmath>

std::string add_commas(const std::string& input)
{
    auto s = input;

   int n = s.length() - 3;
   int end = (std::stol(input) >= 0) ? 0 : 1; // Support for negative numbers
   while (n > end) {
      s.insert(n, ",");
      n -= 3;
   }
   return s;
}

long simulate_tokens(const long& tokens, const long& tpm, const float& days)
{
    long simulated_tokens, simulated_tpm;
    simulated_tpm = tpm;
    simulated_tokens = tokens;
    for (int i = 1; i <= days * 1440; i++)
    {
        if (i % 240 == 0)
        {
            simulated_tpm++;
        }
        simulated_tokens += simulated_tpm;
    }
    return simulated_tokens;
}

double decimalParse(const std::string& input)
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
    for (int i = 0; i < multi; i++)
    {
        num *= 10; // adds the 0's by multiplying num by 10
    }
    return num;
}

int main()
{
    std::vector<int> best = {0, 0, 0, 0};
    long utokens, tokens, utpm, tpm, spent, besttokens, iterations, bestspent, besttpm, oldbest, betteroldbest = 0;
    int maxtpmlength, mintpmlength, weeklength, daylength; // increase if you reach a cap, will make code slower
    double budget;
    std::string budget_s;
    float days = 0;
    std::cout << "What time frame (days): ";
    std::cin >> days;
    std::cout << "How many tokens: ";
    std::cin >> utokens;
    std::cout << "What tpm: ";
    std::cin >> utpm;
    std::cout << "What's your budget: ";
    std::cin >> budget_s;
    budget = decimalParse(budget_s);
    maxtpmlength = int(budget / 4500) + 1;
    mintpmlength = 10;
    weeklength = int(budget / 499) + 1;
    daylength = 10;
    long length = maxtpmlength;
    length *= mintpmlength;
    length *= weeklength;
    length *= daylength;
    length /= 20;
    // days = (days == 0) ? 1 : days;
    if (budget >= 1000000)
    {
        std::cout << "\nAny number between 1-5 million will take a while. \nPlease do not complain about how slow it takes to do 5 million.\n";
    }
    if (budget >= 10000000)
    {
        std::cout << "\nTBH just be f2p (anything this big will break the code)\n";
        return 1;
    }
    long approxlength = (maxtpmlength + 1) * (mintpmlength + 1) * (daylength + 1) * (weeklength + 1);
    std::cout << "Approx. " << add_commas(std::to_string(approxlength)) << " combinations\n";
    for (int maxtpm = 0; maxtpm <= maxtpmlength; maxtpm++)
    {
        for (int mintpm = 0; mintpm <= mintpmlength; mintpm++)
        {
            for (int week = 0; week <= weeklength; week++)
            {
                for (int day = 0; day <= daylength; day++)
                {
                    iterations++;
                    if (besttokens - oldbest == 0 && day != 0 && budget > 1000)
                    {
                        continue;
                    }
                    if (iterations % length == 0)
                    {
                        if (!((iterations / length) * 5 >= 100) && days >= 1 && budget >= 100000)
                        {
                            // std::cout << "You're " << (iterations / length) * 5 << "% there! (" << add_commas(std::to_string(besttokens - oldbest)) << " improvement)\n";
                            oldbest = besttokens;
                        }
                    }
                    spent = maxtpm * 4500;
                    spent += mintpm * 1620;
                    spent += week * 499;
                    spent += day * 99;
                    if (spent > budget)
                    {
                        continue;
                    }
                    if (weeklength - 1 == week)
                    {
                        weeklength++;
                    }
                    if (maxtpmlength - 1 == maxtpmlength)
                    {
                        maxtpmlength++;
                    }
                    tokens = utokens;
                    tpm = utpm;
                    tpm += maxtpm * 300;
                    tpm += mintpm * 100;
                    tokens += tpm * 10080 * week;
                    tokens += tpm * 1440 * day;
                    // now test if better than before
                    if (simulate_tokens(tokens, tpm, days) > besttokens)
                    {
                        besttokens = simulate_tokens(tokens, tpm, days);
                        bestspent = spent;
                        besttpm = tpm;
                        best[0] = maxtpm;
                        best[1] = mintpm;
                        best[2] = day;
                        best[3] = week;
                    }
                }
            }
        }
    }
    std::cout << "\n\n300 tpm : " << add_commas(std::to_string(best[0])) << " (" << add_commas(std::to_string(best[0] * 4500)) << " R$)" << std::endl;
    std::cout << "100 tpm : " << add_commas(std::to_string(best[1])) << " (" << add_commas(std::to_string(best[1] * 1620)) << " R$)" << std::endl;
    std::cout << "1 day rush : " << add_commas(std::to_string(best[2])) << " (" << add_commas(std::to_string(best[2] * 99)) << " R$)" <<  std::endl;
    std::cout << "1 week rush : " << add_commas(std::to_string(best[3])) << " (" << add_commas(std::to_string(best[3] * 499)) << " R$)";
    std::cout << "\nYou will get ~" << add_commas(std::to_string(besttokens)) << " tokens with " << add_commas(std::to_string(besttpm + int(days * 6))) << " TPM.\n";
    std::cout << "You will have " << budget - bestspent << " R$ left you p2w bozo\n\n";
    std::cout << add_commas(std::to_string(iterations)) << " possible combinations considered.\nAlways be sure to buy TPM before Token Rush.\n\n";
    std::cout << add_commas(std::to_string(abs(iterations - approxlength))) << " off.\n";
    return 0;
}
