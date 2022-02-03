#include <IOstream>
#include "square.h"

using namespace std;

//Square::Square(){};

Square::Square(int length)
{
    _Length = length;
}

int Square::getLength() const
{
    return _Length;
}
// Square Square::operator+(const Square &Other) const
// {
//     int a = Length + Other.getLength();
//     Square sq(a);
//     return sq; // Is this ok to do?
// }
// ostream& Square::operator+=(const Square &Other)
// {
// }
// ostream &operator
