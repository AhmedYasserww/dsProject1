#include "LibrarySystem.h"

void LibrarySystem:: addBook()
{
    cin>>book;

    arr[size++]=book.is_availabilty();

    container.insert_last(book);
}


void LibrarySystem:: print_book()
{
    container.display(book);
}

void LibrarySystem::remove_book() {
    int idToRemove;

    cout << "Enter the ID of the book you want to remove: ";
    cin >> idToRemove;

    Book* foundBook = container.search(idToRemove);

    if (foundBook != nullptr) {

        container.remove(*foundBook);

       cout << "Book with ID " << idToRemove << " has been removed." <<endl;
    } else {
       cout << "Book with ID " << idToRemove << " not found." <<endl;
    }
}
void  LibrarySystem::borrowBook(){
int id ;
cout<<"enter the id of the book which yo want to Borrow it ";
cin>>id ;
Book *foundBook = container.search(id);
if (foundBook != nullptr&&foundBook->is_availabilty()){
    foundBook->borrow();

    cout << "You have successfully borrowed the book." << endl;
        cout<<*foundBook<<endl;
}
else
{
    cout<<"Book  with ID : "<<id<<"not found !!"<<endl;
}

}

void LibrarySystem::return_book() {
    int id;
    cout << "Enter the ID of the book you want to return: ";
    cin >> id;

    Book* foundBook = container.search(id);

    if (foundBook != nullptr) {
        if (foundBook->is_availabilty()) {
            cout << "The book is already available." << endl;
        } else {
            foundBook->return_book();
        }
    } else {
        cout << "Book with ID " << id << " not found." << endl;
    }
}

void LibrarySystem::search() {
    int id;
   cout << "Enter the ID of the book you want to search for: ";
    cin >> id;

    Book* foundBook = container.search(id);

    if (foundBook != nullptr) {
        cout << "Book with ID " << id << " found:" << endl;
        cout << *foundBook << endl;
    } else {
        cout << "Book with ID " << id << " not found." << endl;
    }
}
void  LibrarySystem::get_statistic()
{

 int count_av=0, count_bor=0;

for(int i=0 ; i<size ;++i){
 if(arr[i] == true)
    ++count_av;

    else
   ++count_bor;
}

  int  count_all=count_av+count_bor;


    cout<<"Books are available : " <<count_av<<endl;
    cout<<"Books are borrow : " <<count_bor<<endl;
    cout<<"Total Book Is :  "<<count_all<<endl;

}
void LibrarySystem::sortBooksByTitle() {

    container.Sort();
}



LibrarySystem::LibrarySystem()
{
 size=0;

}
LibrarySystem::~LibrarySystem()
{


}
