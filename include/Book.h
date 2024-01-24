#ifndef BOOK_H
#define BOOK_H
#include <iostream>
#include<windows.h>
using namespace std;
class Book
{


public:
    string title;
    string author;
    string ISBN;
    string genre;
   int number ;
 bool availability;
 string availabilityStatus() const ;
 bool operator<(const Book &other) const;


    string get_title();
    string get_author();
    string get_ISBN();

    bool is_availabilty();
    void borrow();
    void return_book();
    int get_number();


    bool operator==(const Book &other);

    friend ostream& operator<<(ostream &out, const Book &book);
    friend istream& operator>>(istream &in, Book &book);

    Book(string title, string auther, string ISBN, string genre, bool availability);

    virtual ~Book();
    Book();
};



#endif // BOOK_H
