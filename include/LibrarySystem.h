#ifndef LIBRARYSYSTEM_H
#define LIBRARYSYSTEM_H
#include <Book.h>
#include <Container.h>
#include <iostream>
using namespace std;
class LibrarySystem
{
public:
       Container <Book> container;
    Book book;
    void addBook();
    void print_book();
    void remove_book();
    void borrowBook();
    void search();
    void return_book();
    void sortBooksByTitle();
//    getTotalBorrowedBooks();
//    getTotalAvailableBooks();
void get_statistic();
void get_statistic2();
  int size;
  int arr [10];
    LibrarySystem();
    virtual ~ LibrarySystem();






};

#endif // LIBRARYSYSTEM_H

