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

int main()
{
    cout << "Ready For the FInal?" << endl;
    // vTest();
    // testCat();
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

    return -1;
}