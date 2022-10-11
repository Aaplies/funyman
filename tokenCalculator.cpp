#include <iostream>
#include <cmath>
#include <vector>
#include <string>

void tester(char charToTest, std::vector<char>& nums, std::string& multiplier)
{
    if (isdigit(charToTest) == true)
    {
        nums.push_back(charToTest);
    } else if (charToTest != ','){
        multiplier = charToTest;
    }
}

long parse(std::string input)
{
    std::vector <char> nums;
    std::string multiplier;
    int multiplierInt = 0;
    std::string num;
    
    int N = 0;
    int K = 3;
    int M = 6;
    int B = 9;
    // only up to 999b or you're typin it urself
    
    for (int i = 0; i < input.size(); i++)
    {
        tester(input[i], nums, multiplier);
    }
    
    if (multiplier == "K" || multiplier == "k")
    {
        multiplierInt = K;
    } else if (multiplier == "M" || multiplier == "m") {
        multiplierInt = M;
    } else if (multiplier == "B" || multiplier == "b") {
        multiplierInt = B;
    } else {
        multiplierInt = N;
    }
    
    for (int i = 0; i < nums.size(); i++)
    {
        num = num + nums[i];
    }
    
    if (multiplierInt != N)
    {
        for (int i = 0; i < multiplierInt; i++)
        {
            num = num + "0";
        }
    }
    return std::stol(num);
}

bool testForGoal(int goal, float current)
{
    if (current >= goal)
    {
        return true;
        // true meaning your goal has been reached
    }
    else
    {
        return false;
    }
}

int main()
{
    std::string goalAbb;
    float goal;
    std::string currentAbb;
    float current;
    std::string giventpmAbb;
    float giventpm;
    
    std::cout << "What is your goal: ";
    std::cin >> goalAbb;
    if (goalAbb == "usage")
    {
        std::cout << "You can type in most formats, K to B, the following are some examples:\n120B\n980K\n9,803\n128009" << std::endl;
        return 0;
    }
    std::cout << "What is your current tokens: ";
    std::cin >> currentAbb;
    std::cout << "What is your tpm: ";
    std::cin >> giventpmAbb;
    
    giventpm = parse(giventpmAbb);
    goal = parse(goalAbb);
    current = parse(currentAbb);
    float tpm = giventpm;
    
    // uncomment for debugging std::cout << tpm << " " << goal << " " << current << std::endl;
    
    try {
        if (goal < current)
        {
            throw 1;
        } else if (tpm < 0) 
        {
            throw 2;
        }
    }
    catch (int code) {
        std::cout << "Error " << code << ", terminating program" << std::endl;
        std::abort();
    }
    
    
    // std::cout << giventpm << " " << goal << " " << current << std::endl;
    bool isClassic;
    std::cout << "Are you playing classic? (1 = true; 0 = false): ";
    std::cin >> isClassic;
    // which version you're playing
    
    bool considerWeeklies = false;
    // consider the 9.3k per week
    
    int vip = 1;
    // 2 for people with vip
    
    try
    {
        if (vip < 0)
        {
            throw 3;
        } else if (vip > 2)
        {
            throw 4;
        }
    }
    catch (int code)
    {
        std::cout << "Error " << code << ", terminating program" << std::endl;
        std::abort();
    }
    
    int i = 0;
    while (testForGoal(goal, current) == false)
    {
        current += (tpm/60);
        i += 1;
        if (isClassic != true && i % 14440 == 0)
        {
            tpm += 1;
        }
        if (considerWeeklies == true && i % 604800 == 0)
        {
            goal -= 9300 * vip;
        }
    }
    int answerHours = round(i / 3600);
    int answerMinutes = (i / 60) - (answerHours * 60);
    int answerSeconds = i - ((answerMinutes * 60) + (answerHours * 3600));
    int answerDays = answerHours / 24;
    float days = answerDays;
    days *= 360;
    float roberVideos = answerDays / 30.5;
    
    std::cout << "\nQuack. It would take roughly around " << answerDays << " days, " << answerHours - (answerDays * 24) << " hours, " << answerMinutes << " minutes, and " << answerSeconds << " seconds." <<std::endl;
    std::cout << "\nThat is " << i << " seconds, or " << i / 60 << " minutes\n" << std::endl;
    std::cout << "The earth will have rotated " << days << " degrees while you afk. (minimum 15)" << std::endl;
    std::cout << "You could listen to fireflies " << i / 225 << " times while you afk" << std::endl;
    std::cout << "Mark rober will post " << roberVideos << " times while you afk. (meant to be a decimal)" << std::endl;
    return 0;
}
