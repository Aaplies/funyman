#include <iostream>
#include <vector>

int main()
{
    double tokens, tpm, usertpm, spent, bestspent, budget, besttokens, days = 0;
    std::vector<int> best = {0, 0, 0, 0, 0}; // 300, 3000, week, month, year
    int Mlength, yearlength, length, weeklength, monthlength, mlength = 0;
    long iterations;
    std::cout << "TPM: ";
    std::cin >> usertpm;
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
                        for (int t100 = 0; t100 <= 3; t100++)
                        {
                            for (int day = 0; day <= 6; day++)
                            {
                                iterations++;
                                spent = mTPM * 4500;
                                spent += MTPM * 30000;
                                spent += t100 * 1620;
                                spent += month * 1499;
                                spent += year * 9999;
                                spent += week * 499;
                                spent += day * 99;
                                if (spent > budget)
                                {
                                    continue;
                                }
                                tpm = usertpm;
                                tpm += mTPM * 300;
                                tpm += MTPM * 3000;
                                tpm += t100 * 100;
                                tokens = 0;
                                tokens += tpm * week * 10080;
                                tokens += tpm * month * 43800;
                                tokens += tpm * year * 525600;
                                tokens += tpm * day * 1440;
                                if (tokens > besttokens)
                                {
                                    besttokens = tokens;
                                    bestspent = spent;
                                    best[0] = mTPM;
                                    best[1] = MTPM;
                                    best[2] = week;
                                    best[3] = month;
                                    best[4] = year;
                                    best[5] = t100;
                                    best[6] = day;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    std::cout << "\n100 tpm : " << best[5] << "\n";
    std::cout << "300 tpm : " << best[0] << "\n";
    std::cout << "3000 tpm : " << best[1] << "\n";
    std::cout << "\n1 day rush : " << best[6] << "\n";
    std::cout << "1 week rush : " << best[2] << "\n";
    std::cout << "1 month rush : " << best[3] << "\n";
    std::cout << "1 year rush : " << best[4] << "\n";
    std::cout << float(besttokens) << " tokens and " << budget - bestspent << " R$ left\n";
    std::cout << "\n" << float(iterations) << " combos considered.\n";
    std::cout << besttokens / bestspent << " tokens per 1 R$\n";
    return 0;
}
