#include <iostream>
using namespace std;

class Square
{
    friend ostream &operator<<(ostream &Out, const Square &Sq);

private:
    int _Length;

public:
    //Square();
    explicit Square(int length);
    int getLength() const;
    //Square operator+(const Square &Other) const;
    //Square &operator+=(const Square &Other);
};