#include <IOstream>
#include "book.h"
using namespace std;

// Constructor:
Book::Book(string title, string author, int pages, string genre)
{
    _title = title;
    _author = author;
    _pages = pages;
    _genre = genre;
}

//Return title of the Book
string Book::getTitle() const
{
    return _title;
}

//Return Author of the Book
string Book::getAuthor() const
{
    return _author;
}

//Return page number of the Book
int Book::getPages() const
{
    return _pages;
}

//Return the genre of the Book
string Book::getGenre() const
{
    return _genre;
}

//Turn the page of the Book forward one page
bool Book::turnPageFWD()
{
    return false;
}

//Turn back a page
bool Book::turnPageBCK()
{
    return false;
}

int Book::getCurrentPage()
{
    return _currentPage;
}
// int main()
// {
//     Book b1 = Book("Software Engineering", "Ian Sommerville", 796, "Textbook");

//     cout << b1.getTitle() << " " << b1.getAuthor() << endl;

//     return 0;
// }
