#include <iostream>
#include <vector>

int main()
{
    double tokens, tpm, usertokens, usertpm, spent, bestspent, budget, besttokens, days = 0;
    std::vector<int> best = {0, 0, 0, 0, 0}; // 300, 3000, week, month, year
    int Mlength, yearlength, length, weeklength, monthlength, mlength, iterations = 0;
    std::cout << "TPM: ";
    std::cin >> usertpm;
    std::cout << "Tokens: ";
    std::cin >> usertokens;
    std::cout << "Budget: ";
    std::cin >> budget;
    Mlength = int(budget / 4500) + 1;
    yearlength = int(budget / 9999) + 1;
    for (int mTPM = 0; mTPM <= 7; mTPM++)
    {
        for (int MTPM = 0; MTPM <= Mlength; MTPM++)
        {
            for (int month = 0; month <= 7; month++)
            {
                for (int week = 0; week <= 4; week++)
                {
                    for (int year = 0; year <= yearlength; year++)
                    {   
                        iterations++;
                        spent = mTPM * 4500;
                        spent += MTPM * 30000;
                        spent += month * 1499;
                        spent += year * 9999;
                        spent += week * 499;
                        if (spent > budget)
                        {
                            continue;
                        }
                        tpm = usertpm;
                        tpm += mTPM * 300;
                        tpm += MTPM * 3000;
                        tokens = usertokens;
                        tokens += tpm * week * 10080;
                        tokens += tpm * month * 43800;
                        tokens += tpm * year * 525600;
                        if (tokens > besttokens)
                        {
                            besttokens = tokens;
                            bestspent = spent;
                            best[0] = mTPM;
                            best[1] = MTPM;
                            best[2] = week;
                            best[3] = month;
                            best[4] = year;
                        }
                    }
                }
            }
        }
    }
    std::cout << "\n300 tpm : " << best[0] << "\n";
    std::cout << "3000 tpm : " << best[1] << "\n";
    std::cout << "1 week rush : " << best[2] << "\n";
    std::cout << "1 month rush : " << best[3] << "\n";
    std::cout << "1 year rush : " << best[4] << "\n";
    std::cout << float(besttokens) << " tokens and " << budget - bestspent << " R$ left\n";
    std::cout << "\n" << float(iterations) << " combos considered.\n";
    return 0;
}
