#include "book.h"
#include <iostream>
using namespace std;

// Constructor:
Book::Book(const string title, const string author) : Title{title}, Author{author} //, int pages) //, string genre)
{
}
// //Return title of the Book
string Book::getTitle() const
{
    return this->Title;
}

// //Return Author of the Book
string Book::getAuthor() const
{
    return this->Author;
}

// //Return page number of the Book
// int Book::getPages()
// {
//     return _pages;
// }

// //Return the genre of the Book
// string Book::getGenre()
// {
//     return _genre;
// }

// //Turn the page of the Book forward one page
// bool Book::turnPageFWD()
// {
//     return false;
// }

// //Turn back a page
// bool Book::turnPageBCK()
// {
//     return false;
// }

// int Book::getCurrentPage()
// {
//     return _currentPage;
// }
