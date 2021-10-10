// #ifndef BOOK_
// #define BOOK_
#include <iostream>
using namespace std;

class Book
{
private:
    string Title;
    string Author;
    //int Pages;
    // string _genre;

public:
    Book(const string title, const string author); //,int Pages); //, string _genre);

    //Return title of the Book
    string getTitle() const;

    //     //Return Author of the Book
    string getAuthor() const;
};

//#endif

/* Interfaces of a Book*/

//Getter methods should have cont in the method header

//     //Return page number of the Book
//     int getPages();

//     //Return the genre of the Book
//     string getGenre();

//     //return the current page number
//     int getCurrentPage();

//     //Turn the page of the Book forward one page
//     bool turnPageFWD();

//     //Turn back a page
//     bool turnPageBCK();