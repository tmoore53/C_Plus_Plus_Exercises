#include <iostream>
using namespace std;

int main()
{
    int age;

    cout << "Hello world. How old are you (in years)?\n";

    cin >> age;

    cout << "That is " << 365 * age << " days." << endl;

    return 0;
}
