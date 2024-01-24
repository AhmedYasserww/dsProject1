#include <iostream>
#include "LibrarySystem.h"
using namespace std;
int main()
{
    LibrarySystem library;

    while (true)
    {
        cout <<"\t\t\t\t-------------------------------------"<<endl;
        cout << "\t\t\t\t\tLibrary System Management " << endl;
        cout <<"\t\t\t\t-------------------------------------"<<endl;
        cout<<"\n  Main Menu :) ->\n"<<endl;
        cout << "1. Add a book" << endl;
        cout << "2. Print all books" << endl;
        cout << "3. Search for a book by ID" << endl;
        cout << "4. Borrow a book" << endl;
        cout << "5. Return a book" << endl;
        cout << "6. Remove a book" << endl;
        cout << " 7.Show Statistic "<<endl;
        cout <<"8. Sort Books "<<endl;
        cout << "9. Exit" << endl;
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;
        system ("cls");
        switch (choice)
        {
        case 1:
        {

            library.addBook();
            break;
        }

        case 2:
        {
            library.print_book();
            break;
        }
        case 3 :
        {
            library.search();
            break;
        }
        case 4:
        {

            library.borrowBook();
            break;
        }
        case 5:
        {
            library.return_book();
            break;
        }

        case 6 :
        {
            library.remove_book();
            break;
        }
        case 7 :
        {
            library.get_statistic();
            break;
        }
        case 8 :
            {
                library.sortBooksByTitle();
                break;
            }

        case 9:
        {
            cout << " THANKS " << endl;
            return 0;
        }
        default:
            cout << "EROR" << endl;
        }
    }

    return 0;
}
