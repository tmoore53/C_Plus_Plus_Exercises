#include <IOstream>
#include <cassert>
#include <sstream>

using namespace std;

void truthTable(int numberOfPropostions, const string &sofar = "")
{
    string row = "TTT";

    if (numberOfPropostions <= 1)
    {
        cout << sofar << "T" << endl;
        cout << sofar << "F" << endl;
    }
    else
    {
        truthTable(numberOfPropostions - 1, sofar + "T");
        truthTable(numberOfPropostions - 1, sofar + "F");
    }
}

int main()
{
    truthTable(3);
    return 0;
}