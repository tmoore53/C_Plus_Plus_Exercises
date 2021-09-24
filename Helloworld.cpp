#include <iostream>

using namespace std;

int main()
{
    cout << "Hello World" << endl;
    int height = 8;

    for (int i = 0; i < height; i++)
    {
        /* code */

        for (int j = height - 1; j > i; j--)
        {
            /* code */
            cout << " ";
        }
        for (int k = 0; k <= i; k++)
        {
            /* code */
            cout << "#";
        }
        cout << " ";
        for (int j = 0; j < i + 1; j++)
        {
            cout << "#";
        }
        for (int k = 0; k <= i; k++)
        {
            /* code */
            cout << " ";
        }
        cout << endl;
    }
}