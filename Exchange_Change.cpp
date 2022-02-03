#include <iostream>
using namespace std;

// int main()
// {
//     float x = .41;

//     float nickel = .05;
//     float dime = .10;
//     float quarter = .25;
//     float penny = .01;

//     // expected 4

//     //.01 = 1

//     //.15 = 2

//     //1.6 = 7

//     // cin >> x;

//     cout << x << endl;

//     int coins = 0;

//     while (x >= 0)
//     {
//         cout << "Current amount of coins: " << coins << endl;

//         while (x >= quarter)
//         {
//             x -= .25;
//             coins = coins + 1;
//             cout << "Current amount of coins: 1 Quarter | "
//                  << "Current amount of coins: " << coins << " X = " << x << endl;
//         }
//         while (x >= dime)
//         {
//             x -= .10;
//             coins = coins + 1;
//             cout << "Current amount of coins: 1 Dime | "
//                  << "Current amount of coins: " << coins << " X = " << x << endl;
//         }
//         while (x >= nickel)
//         {
//             x -= .05;
//             coins = coins + 1;
//             cout << "Current amount of coins: 1 Nickel | "
//                  << "Current amount of coins: " << coins << " X = " << x << endl;
//         }

//         while (x >= 0)
//         {
//             coins = coins + 1;
//             x -= .01;

//             cout << "Current amount of coins: 1 Penny | "
//                  << "Current amount of coins: " << coins << " X = " << x << endl;
//         }
//         cout << "Final output of coins: " << coins << " X = " << x << endl;
//     }

//TODO: Why does x -= .01 return -4.88013e-09
// double testf = .1;
// double testa = .1 - .1;

// while (testf > -.5)
// {
//     testf -= .01;
//     cout << testf << endl;
// }
// cout << testa << endl;

// cout << "Final output of coins: " << coins << " X = " << x << endl;
// }