/* 
300 is 4,500
100 is 1,620
1 day is 99
1 week is 499
*/
#include <iostream>
#include <vector>

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

int main()
{
    std::vector<int> best = {0, 0, 0, 0};
    long utokens, tokens, utpm, tpm, budget, spent, besttokens, iterations, bestspent, besttpm = 0;
    int maxtpmlength, mintpmlength, weeklength, daylength; // increase if you reach a cap, will make code slower
    float days = 0;
    std::cout << "What time frame (days): ";
    std::cin >> days;
    std::cout << "How many tokens: ";
    std::cin >> utokens;
    std::cout << "What tpm: ";
    std::cin >> utpm;
    std::cout << "What's your budget: ";
    std::cin >> budget;
    maxtpmlength = (budget / 4500);
    mintpmlength = 10;
    weeklength = (budget / 499);
    daylength = 10;
    long length = maxtpmlength;
    length *= mintpmlength;
    length *= weeklength;
    length *= daylength;
    length /= 10;
    // days = (days == 0) ? 1 : days;
    if (budget >= 1000000)
    {
        std::cout << "\nAny number between 1-5 million will take a while. \nPlease do not complain about how slow it takes to do 10 million.\n";
        std::cout << "Progress messages turned on cause this'll take longer than usual\n\n";
    }
    if (budget >= 10000000)
    {
        std::cout << "\nTBH just be f2p (anything this big will break the code)\n";
        return 1;
    }
    for (int maxtpm = 0; maxtpm <= maxtpmlength; maxtpm++)
    {
        for (int mintpm = 0; mintpm <= mintpmlength; mintpm++)
        {
            for (int week = 0; week <= weeklength; week++)
            {
                for (int day = 0; day <= daylength; day++)
                {
                    iterations++;
                    if (iterations % length == 0)
                    {
                        if (!((iterations / length) * 10 >= 100) && budget >= 1000000)
                        {
                            std::cout << "You're " << (iterations / length) * 10 << "% there!\n";
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
                    if ((tpm * days * 1440) + tokens > besttokens)
                    {
                        besttokens = (tpm * days * 1440) + tokens;
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
    std::cout << "\n\n300 tpm : " << add_commas(std::to_string(best[0])) << std::endl;
    std::cout << "100 tpm : " << add_commas(std::to_string(best[1])) << std::endl;
    std::cout << "1 day rush : " << add_commas(std::to_string(best[2])) << std::endl;
    std::cout << "1 week rush : " << add_commas(std::to_string(best[3])) << std::scientific;
    std::cout << "\nYou will get " << add_commas(std::to_string(besttokens)) << " tokens with " << add_commas(std::to_string(besttpm + int(days * 6))) << " TPM.\n";
    std::cout << "You will have " << budget - bestspent << " R$ left you p2w bozo\n\n";
    std::cout << add_commas(std::to_string(iterations)) << " possible combinations considered.\nAlways be sure to buy TPM before Token Rush.\n";
}
