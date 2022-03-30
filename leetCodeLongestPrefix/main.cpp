#include <iostream>
#include <set>
#include <vector>
#include <stack>

// using namespace std;

std::string lengthOfLongestSubstring(const std::vector<std::string> s)
{
    std::string longestPrefix = s[0];

    for (const auto str : s)
    {
        for (int i{0}; i < str.size(); i++)
        {
            if (str[i] != longestPrefix[i])
            {
                longestPrefix = longestPrefix.substr(0, i);
                break;
            }
        }
    }
    return longestPrefix;
}
void test1()
{
    std::cout << "Begining of Test1" << std::endl;
    std::vector<std::string> test1 = {"apple", "application"};
    std::cout << lengthOfLongestSubstring(test1) << std::endl;
    std::cout << "Ending Test1" << std::endl;
}
void test2()
{
    std::cout << "Begining of Test 2" << std::endl;
    std::vector<std::string> test1 = {"application", "apple"};
    std::cout << lengthOfLongestSubstring(test1) << std::endl;
    std::cout << "Ending Test 2" << std::endl;
}
void test3()
{
    std::cout << "Begining of Test 3" << std::endl;
    std::vector<std::string> test1 = {"", "application"};
    std::cout << lengthOfLongestSubstring(test1) << std::endl;
    std::cout << "Ending Test 3" << std::endl;
}
void test3_()
{
    std::cout << "Begining of Test 3_" << std::endl;
    std::vector<std::string> test1 = {"", "application"};
    std::cout << lengthOfLongestSubstring(test1) << std::endl;
    std::cout << "Ending Test 3_" << std::endl;
}
void test4()
{
    std::cout << "Begining of Test 4" << std::endl;
    std::vector<std::string> test1 = {"flower", "flow", "flight"};
    std::cout << lengthOfLongestSubstring(test1) << std::endl;
    std::cout << "Ending Test 4" << std::endl;
}
void test5()
{
    std::cout << "Begining of Test 5" << std::endl;
    std::vector<std::string> test1 = {"dog", "racecar", "car"};
    std::cout << lengthOfLongestSubstring(test1) << std::endl;
    std::cout << "Ending Test 5" << std::endl;
}
std::vector<int> removeTarget(std::vector<int> arr, int target)
{
    std::vector<int> leftOver;
    for (int i{0}; i < arr.size(); i++)
    {
        if (arr[i] != target)
        {
            leftOver.push_back(arr[i]);
        }
    }
    return leftOver;
}
void test105()
{
    std::cout << "Begining of Test 105" << std::endl;
    std::vector<int> test = {1, 1, 2, 2, 3, 3, 4, 4};
    std::vector<int> testResult = removeTarget(test, 2);
    std::cout << "Target: " << 2;

    std::cout << "[";

    for (const auto n : testResult)
    {
        std::cout << n;
    }
    std::cout << "]" << std::endl;

    std::cout << "Ending Test 105" << std::endl;
}
void test106()
{
    std::cout << "Begining of Test 106" << std::endl;
    std::vector<int> test = {1, 1, 2, 2, 3, 3, 4, 4};
    std::vector<int> testResult = removeTarget(test, 4);
    std::cout << "Target: " << 4;

    std::cout << "[";

    for (const auto n : testResult)
    {
        std::cout << n;
    }
    std::cout << "]" << std::endl;

    std::cout << "Ending Test 106" << std::endl;
}
int main()
{
    // test1();
    // test2();
    // test3();
    // test3_();
    // test4();
    // test5();
    test105();
    test106();
    return -1;
}