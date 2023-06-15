#include <iostream> // you may see a version of this in peace's bot, this is the original. They may or may not decide to change things with this
#include <vector> //   but at this point it ALWAYS goes over the goal

int main()
{
    double token_goal = 0.0, user_tpm = 0.0, tpm = 0.0, spent = 0.0, tokens = 0.0, bestspent = 0.0, closest = 0.0;
    std::vector<int> best_set = {0, 0, 0, 0, 0, 0, 0};
    int iterations = 0;
    std::cout << "Token Goal: ";
    std::cin >> token_goal;
    std::cout << "TPM: ";
    std::cin >> user_tpm;
    closest = token_goal;
    for (int mTPM = 0; mTPM < 7; mTPM++)
    {
        for (int MTPM = 0; MTPM <= 50; MTPM++)
        {
            for (int month = 0; month <= 7; month++)
            {
                for (int week = 0; week <= 4; week++)
                {
                    for (int year = 0; year <= 50; year++)
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
                                tpm = user_tpm;
                                tpm += mTPM * 300;
                                tpm += MTPM * 3000;
                                tpm += t100 * 100;
                                tokens = 0;
                                tokens += tpm * week * 10080;
                                tokens += tpm * month * 43800;
                                tokens += tpm * year * 525600;
                                tokens += tpm * day * 1440;
                                if (tokens < token_goal)
                                {
                                    continue;
                                }
                                else if (tokens - token_goal < closest)
                                {
                                    closest = tokens - token_goal;
                                    // std::cout << closest << "\n";
                                    bestspent = spent;
                                    best_set[0] = mTPM;
                                    best_set[1] = MTPM;
                                    best_set[2] = month;
                                    best_set[3] = week;
                                    best_set[4] = year;
                                    best_set[5] = t100;
                                    best_set[6] = day;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    std::cout << "100 TPM: " << best_set[5] << "\n";
    std::cout << "300 TPM: " << best_set[0] << "\n";
    std::cout << "3000 TPM: " << best_set[1] << "\n";
    std::cout << "\n1 day rush: " << best_set[6] << "\n";
    std::cout << "1 week rush: " << best_set[3] << "\n";
    std::cout << "1 month rush: " << best_set[2] << "\n";
    std::cout << "1 year rush: " << best_set[4] << "\n";
    std::cout << "\nRobux: " << bestspent << "\n";
    std::cout << "Tokens away: " << closest << "\n";
    std::cout << "Tokens: " << token_goal + closest << "\n";
    std::cout << "Iterations: " << iterations << "\n";
    return 0;
}
