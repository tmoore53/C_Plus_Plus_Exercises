#include <iostream>
using namespace std;

int main()
{
    float x = .15;

    float nickel = .05;
    float dime = .1;
    float quarter = .25;
    float penny = .01;

    // expected 4

    //.01 = 1

    //.15 = 2

    //1.6 = 7

    // cin >> x;

    cout << x << endl;

    int coins = 0;

    while (x >= penny)
    {
        cout << "Current amount of coins: " << coins << endl;

        while (x >= quarter)
        {

            x -= .25;
            coins = coins + 1;
            cout << "Current amount of coins: " << coins << " Quarter" << endl;
        }
        while (x >= dime)
        {
            x -= .10;
            coins = coins + 1;
            cout << "Current amount of coins: " << coins << " Dime" << endl;
        }
        while (x >= nickel)
        {
            x -= .5;
            coins = coins + 1;
            cout << "Current amount of coins: " << coins << " Nickel" << endl;
        }
        //Does not pickup this statement
        while (x >= penny)
        {
            coins = coins + 1;
            x -= .01;

            cout << "Current amount of coins: " << coins << " Penny" << endl;
        }
    }
    cout << "Final output of coins: " << coins << endl;
}