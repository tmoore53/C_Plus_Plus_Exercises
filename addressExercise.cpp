#include <IOstream>

using namespace std;
class GlobalFunction
{
public:
    GlobalFunction()
    {
        largestNum();
    }

    void largestNum()
    {
        int num1;
        int num2;

        bool input = true;
        string answer;

        while (input)
        {
            cout << "Please input a number ";
            cin >> num1; //>> num2;
            cout << "Please input another number ";
            cin >> num2;

            if (num1 < num2)
            {
                cout << num2 << " is the largest number of the two";
            }
            else
            {
                cout << num1 << " is the largest number of the two";
            }

            cout << "Do you want to continue?";
            cin >> answer;
            if (answer == "y")
            {
                input = true;
            }
            else
            {
                input = false;
            }
        }
    }
};

GlobalFunction firstGF;

int main()
{

    int number = 3;

    // * allows you to modify number because it points to the &{variable}
    int *np = &number;

    cout << &number;

    // *np is pointing to the numner's memory address pPrints out memory address.
    cout << *np << endl;

    cout << "Test" << endl;
    return 0;
}

void TestArray()
{
    int nums[10];
    nums[0] = 23;
    for (int i(0); i < 10; i++)
    {
        cout << nums[i] << endl;
        /* code */
    }
}