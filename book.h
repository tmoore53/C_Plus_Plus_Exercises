using namespace std;
#ifndef BOOK_
#define BOOK_
class Book
{
private:
    string _title;
    string _author;
    int _pages;
    string _genre;
    int _currentPage;

public:
    Book(string title, string author, int pages, string genre);

    /* Interfaces of a Book*/

    //Return title of the Book
    string getTitle() const;

    //Return Author of the Book
    string getAuthor() const;

    //Return page number of the Book
    int getPages() const;

    //Return the genre of the Book
    string getGenre() const;

    //return the current page number
    int getCurrentPage();

    //Turn the page of the Book forward one page
    bool turnPageFWD();

    //Turn back a page
    bool turnPageBCK();
};

#endif
