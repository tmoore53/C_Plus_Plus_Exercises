#include <iostream>
#include <map>
#include <unordered_map>
#include <stack>
#include <set>

using namespace std;
bool isHappy(int n)
{

    int digit1;
    set<int> seen;

    while (seen.count(n) == 0)
    {
        if (n == 1)
        {
            return true;
        }
        cout << "N = " << n << endl;
        seen.insert(n);
        digit1 = 0;

        while (n)
        {
            digit1 += (n % 10) * (n % 10);
            n /= 10;
        }
        n = digit1;
    }
    return false;
}
int main()
{
    unordered_map<string, int> um;

    cout << isHappy(19) << endl;
    cout << isHappy(7) << endl;
    cout << isHappy(2) << endl;
    cout << isHappy(59) << endl;

    return -1;
}