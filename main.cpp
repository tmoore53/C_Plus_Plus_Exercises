#include <IOstream>
//#include "addressExercise.cpp"
#include "book.h"

using namespace std;

int main()
{
    Book b1 = Book("Software Engineering", "Ian Sommerville", 796, "Textbook");

    cout << b1.getTitle() << " " << b1.getAuthor() << endl;

    return 0;
}
