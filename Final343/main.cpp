#include <IOstream>
#include <cassert>
//#include "linkedList.cpp"
#include <sstream>
#include <map>
#include <vector>

using namespace std;
int sum(int a, int b) { return a + b; }
int mul(int a, int b) { return a * b; }

int vOperator(vector<int> v, int func(int a, int b))
{
    int total = v[0];
    for (int i{1}; i < v.size(); i++)
    {
        total = func(total, v[i]);
    }
    cout << total << endl;
    return total;
}

void vTest()
{
    vector<int> v{2, 5, 3, 1};
    assert(11 == vOperator(v, sum));
    assert(30 == vOperator(v, mul));
}
class Animal
{
    friend ostream &operator<<(ostream &out, const Animal &c)
    {
        return c.printerHelper(out);
    }

private:
protected:
    int age;

    virtual ostream &printerHelper(ostream &out) const
    {
        return out << "<A: " << age << ">";
    }

public:
    Animal(){};
    Animal(int age) = delete;
};

class Cat : public Animal
{

private:
    ostream &printerHelper(ostream &out) const override
    {
        return out << "<C: " << age << ">";
    }

public:
    Cat(int age) { this->age = age; };
};

void testCat()
{
    Cat *c = new Cat(7);
    cout << *c << endl;

    Animal *a = new Cat(5);
    cout << *a << endl;
}

void bitMinip_()
{
    vector<char> ch = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L'};

    cout << "Before any Changes" << endl;
    for (const auto c : ch)
    {
        cout << c;
    }
    cout << endl;

    cout << "ORR Gate \" \" " << endl;
    for (int i{0}; i < ch.size(); i++)
    {
        ch[i] = ch[i] | ' ';
    }
    cout << endl;

    for (const auto c : ch)
    {
        cout << c;
    }
    cout << endl;

    cout << "AND Gate _ " << endl;
    for (int i{0}; i < ch.size(); i++)
    {
        ch[i] = ch[i] & '_';
    }
    for (const auto c : ch)
    {
        cout << c;
    }
    cout << endl;

    cout << "Adding 32 " << endl;
    for (int i{0}; i < ch.size(); i++)
    {
        ch[i] = ch[i] + 32;
    }
    for (const auto c : ch)
    {
        cout << c;
    }
    cout << endl;

    cout << "Subtracting 32 " << endl;
    for (int i{0}; i < ch.size(); i++)
    {
        ch[i] = ch[i] - 32;
    }
    for (const auto c : ch)
    {
        cout << c;
    }
    cout << endl;
    cout << endl;
    char temp = 'a';
    temp = temp & '_';
    cout << temp << endl;

    int num = 0x80000000;

    cout << "Num = " << num << endl;
    num--;

    cout << "Num = " << num << endl;
}

void multiplyByShifting()
{
    int R0 = 30;
    cout << "With multiply by 10: " << R0 * 10 << endl;
    R0 = 30;
    int R1 = R0 << 3;
    int R2 = R0 << 1;
    R0 = R1 + R2;
    cout << "With bit shift: " << R0 << endl;

    // 100 (Base 10) = 0110 0100 (Base 2)
    //  0       1       1       0       0       1       0       0
    // 0*2^7 + 1*2^6 + 1*2^5 + 0*2^4 + 0*2^3 + 1*2^2 + 0*2^1 + 0*2^0
    //    0   +   64  +   32  +   0   +  0   +  4    +   0  +   0  =
    R0 = 30;
    cout << "With multiply by 100: " << R0 * 100 << endl;
    R1 = 0;
    R2 = 0;
    R0 = 30;
    R1 = R0 << 6;
    int R3 = R0 << 5;
    int R4 = R0 << 2;
    // R2 = R0 << 2;
    R0 = R1 + R3 + R4;
    cout << "With bit shift: " << R0 << endl;

    cout << "With bit shift in one line: " << R0 << endl;
}

void logicalOps()
{
    int R0 = 20;
    int R1 = 10;
    int R2 = 5;
    int R3, R4 = 0;

    if (R0 >= R1)
    {
        R3 = R0 - R2;
    }
    // R0 >= R2
    // R3 >= 0
    if (R3 >= 0)
    {
        R0 = 25;
    }
    if (R3 < 0)
    {
        R4 = R2 - R0;
    }
    if (R4 < 0)
    {
        R0 = 15;
    }

    cout << "R0: " << R0 << " R1: " << R1 << " R2: " << R2 << " R3: " << R3 << " R4: " << R4 << endl;

    int R0 = 20;
    int R1 = 10;
    int R2 = 5;
    int R3 = 0;
    int R4 = 0;

    if (R0 >= R1)
    {
        R3 = R0 - R2;
        if (R3 >= 0)
        {
            R0 = 25;
        }
    }
    else
    {
        R4 = R2 - R0;
        if (R4 < 0)
        {
            R0 = 15;
        }
    }

    cout << "R0: " << R0 << " R1: " << R1 << " R2: " << R2 << " R3: " << R3 << " R4: " << R4 << endl;

    R0 = 10;
    R1 = 20;
    R2 = 5;
    R3 = 0;
    R4 = 0;

    if (R0 >= R1)
    {
        R3 = R0 - R2;
        if (R3 >= 0)
        {
            R0 = 25;
        }
    }
    else if (R0 < R1)
    {
        R4 = R2 - R0;
        if (R4 < 0)
        {
            R0 = 15;
        }
    }

    cout << "R0: " << R0 << " R1: " << R1 << " R2: " << R2 << " R3: " << R3 << " R4: " << R4 << endl;
}

int main()
{
    cout << "Ready For the FInal?" << endl;
    // vTest();
    // testCat();

    return -1;
}