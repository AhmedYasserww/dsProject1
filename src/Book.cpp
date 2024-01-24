#include "Book.h"
#include <iostream>

using namespace std;
string Book::get_title()
{
    return title;
}
string Book::get_author()
{
    return author;
}
string  Book::get_ISBN()
{

    return ISBN;
}
bool Book::is_availabilty()
{
    return availability;
}
void Book::borrow()
{
    if (availability == true)
    {
        availability = false;
    }
    else
    {
        cout<<" book not avilable... "<<endl;
    }

}

void Book::return_book()
{
    if (!availability)
    {
        availability = true;
        cout << "The book has been returned" << endl;

    }
    else
    {
        cout << "The book is already available" << endl;
    }
}
int Book::get_number()
{
    return number;
}

Book::Book(string title, string auther, string ISBN, string genre, bool availability)

{
    this->title = title;
    this->author = auther;
    this->ISBN = ISBN;
    this->genre = genre;

}
bool Book::operator==(const Book &other)
{
    return (title == other.title && author == other.author && ISBN == other.ISBN);
}

ostream& operator<<(ostream &out, const Book &book)
{


    out << " Id is : " << book.number << endl;
    out << " Title  is : " << book.title << endl;
    out << " Author is : " << book.author << endl;
    out << " ISBN  is : " << book.ISBN << endl;
 out << " Availability: " << book.availabilityStatus()<<endl<<endl;
 out<<"-------------------------------------------"<<endl;

    return out;
}

istream& operator>>(istream &in, Book &book)
{

    cout << "Enter id: ";
    in>> book.number;
    cout << "Enter Title: ";
    in >> book.title;
    cout << "Enter Author: ";
    in>>book.author;
    cout << "Enter ISBN: ";
    in>> book.ISBN;

    cout << "Enter genre: ";
    in>> book.genre;
    cout<< "is availabilty[y / N] : ";
    char ch;
    in>>ch;
    if(ch=='y'||ch=='Y')
    {
        book.availability=true;
    }
    else
    {
        book.availability=false;
    }
    cout<<endl;
    cout << "SAVED...." << endl;
    Sleep(1000);
    system("cls");
    return in;
}
 string Book:: availabilityStatus() const {
        return availability ? " AVAILABLE" : "BORROWED";
    }
    bool Book::operator<(const Book &other) const {
    return title < other.title;
}


Book::Book()
{
}

Book::~Book()
{

}
