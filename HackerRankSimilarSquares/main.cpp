#include <iostream>
#include <set>
#include <vector>
#include <stack>
int GCD(int n, int m)
{
    if (m == 0)
        return n;
    return GCD(m, n % m);
}
int findGCD(int a, int b)
{
    if (b == 0)
        return a;
    return findGCD(b, a % b);
}
void test1()
{
    std::vector<std::vector<long>> data = {{1, 2}, {2, 4}, {4, 8}, {8, 16}, {16, 32}, {5, 7}, {5, 7}};
    int count{1};
    bool comp = false;
    for (int i{0}; i < data.size(); i++)
    {
        for (int j{i + 1}; j < data.size(); j++)
        {
            // Compare one fraction in the data
            std::cout << "I: " << data[i][0] << "/" << data[i][1] << std::endl;
            std::cout << "J: " << data[j][0] << "/" << data[j][1] << std::endl;
            std::cout << std::endl;
            std::cout << "GCD of I: " << GCD(data[i][0], data[i][1]) << std::endl;
            std::cout << "GCD of J: " << GCD(data[j][0], data[j][1]) << std::endl;
            std::cout << std::endl;

            // Get the Greatest common denominator of each fraction
            int commonD1 = GCD(data[i][0], data[i][1]);
            int commonD2 = GCD(data[j][0], data[j][1]);

            // reduce the fractions by its greatest common denominator
            long numerator1 = data[i][0] / commonD1;
            long denominator1 = data[i][1] / commonD1;
            long numerator2 = data[j][0] / commonD2;
            long denominator2 = data[j][1] / commonD2;

            std::cout << "Simplified I: " << numerator1 << "/" << denominator1 << std::endl;
            std::cout << "Simplified J: " << numerator2 << "/" << denominator2 << std::endl;

            // If there are matching fractions Increase the count by one and continue checking other numbers
            if (numerator1 == numerator2 && denominator1 == denominator2)
            {
                std::cout << "***Hits True***" << std::endl;
                count++;
                break;
            }
        }

        std::cout << "***" << std::endl;
        std::cout << std::endl;
    }
    if (count == 1)
    {
        count = 0;
    }
    std::cout << "Count == " << count << std::endl;
}

// using namespace std;
int main()
{
    test1();

    return -1;
}