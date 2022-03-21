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
    vTest();
    testCat();

    return -1;
}