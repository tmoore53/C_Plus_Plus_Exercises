#include <iostream>
using namespace std;

static double power(double v, int pow)
{
    if (pow > 1)
    {
        return v * power(v, pow - 1);
    }
    return v;
}

int main()
{
    cout << power(2, 2) << endl;
    return -1;
}