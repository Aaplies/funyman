#include <iostream>
#include <vector>

int main()
{
    double tokens = 0.0, tpm = 0.0, usertpm = 0.0, spent = 0.0, bestspent = 0.0, budget = 0.0, besttokens = 0.0, days = 0.0;
    std::vector<int> best = {0, 0, 0, 0, 0, 0, 0}; // 300, 3000, week, month, year
    int Mlength, yearlength, mlength = 0; // how many of a certain item that you can buy- adaptive lengths
    long iterations = 0; // counts the considered combinations
    std::cout << "TPM: ";
    std::cin >> usertpm;
    std::cout << "Budget: "; // user input, blah blah. You know this, right?
    std::cin >> budget;
    Mlength = int(budget / 4500) + 1; // initalizing the adaptive length variables
    yearlength = int(budget / 9999) + 1;
    if (budget <= 0)
    {
        std::cout << "Budget cannot be 0.\n"; // what would you expect?
        return 1;
    }
    else if (usertpm < 5)
    {
		std::cout << "How is your tpm under 5?\n"; // if these weren't here it'd work but I'm too lazy to test
		return 2;//									  every single case for negative numbers, 0's, etc.
    }
	else if (budget >= 10000000)
	{
		std::cout << "This is gonna take a long time. Good luck.\n"; // people will mess with the inputs so much
	}
	else if (budget >= 20000000)
	{
		std::cout << "I won't do this.\n"; // if you REALLY want to do 2e+06 or more add a // at the start of the next line
		return 3;
	}
    for (int mTPM = 0; mTPM <= 7; mTPM++)
    {
        for (int MTPM = 0; MTPM <= Mlength; MTPM++)
        {
            for (int month = 0; month <= 7; month++) // hella for loops; checks every possible combination of stuff
            { //                                        that you can buy
                for (int week = 0; week <= 4; week++)
                {
                    for (int year = 0; year <= yearlength; year++)
                    {
                        for (int t100 = 0; t100 <= 3; t100++)
                        {
                            for (int day = 0; day <= 6; day++)
                            {
                                iterations++; // counter variable
                                spent = mTPM * 4500;
                                spent += MTPM * 30000;
                                spent += t100 * 1620;
                                spent += month * 1499;
                                spent += year * 9999;
                                spent += week * 499; // figures out how much each combination costs
                                spent += day * 99;
                                if (spent > budget)
                                {
                                    continue; // you can't spend more robux than you have
                                }
                                tpm = usertpm;
                                tpm += mTPM * 300;
                                tpm += MTPM * 3000; // tpm buying stuff
                                tpm += t100 * 100;
                                tokens = 0;
                                tokens += tpm * week * 10080;
                                tokens += tpm * month * 43800; // token rushes
                                tokens += tpm * year * 525600;
                                tokens += tpm * day * 1440;
                                if (tokens > besttokens) // if it's better than the previous best
                                {
                                    besttokens = tokens; // makes this the new previous best
                                    bestspent = spent; // statistics
                                    best[0] = mTPM; // saves the combination
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
	if (bestspent < 0 || besttokens < 0)
	{
		std::cout << "There wasn an error.\nBest spent : " << bestspent << "\nBest tokens : " << besttokens << "\n";
		return 4;
	}
    std::cout << "\n100 tpm : " << best[5] << "\n"; // editing all of these couts is pain
    std::cout << "300 tpm : " << best[0] << "\n";
    std::cout << "3000 tpm : " << best[1] << "\n";
    std::cout << "\n1 day rush : " << best[6] << "\n";
    std::cout << "1 week rush : " << best[2] << "\n";
    std::cout << "1 month rush : " << best[3] << "\n";
    std::cout << "1 year rush : " << best[4] << "\n";
    // float(variable) forces it to use scientific notation if it's above 1e+06 or 1,000,000
    std::cout << float(besttokens) << " tokens and " << budget - bestspent << " R$ left\n";
    std::cout << "\n" << float(iterations) << " combos considered.\n";
    if (bestspent != 0) // prevents it from saying "inf"
    {
        std::cout << besttokens / bestspent << " tokens per 1 R$\n";
    }
    return 0; // what would a C++ program be without its beloved return 0;
}
