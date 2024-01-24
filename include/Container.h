#ifndef CONTAINER_H
#define CONTAINER_H
# include <iostream>
#include <algorithm>
using namespace std;
template <typename T>
class Container {
private:
    struct Node {
        T item;
        Node* next;
        Node* prev;
    };
    Node* first;
    Node* last;
    int count;

public:
    Container();
    ~Container();

    void insert_first(const T& element);
    void insert_last(const T& element);
    void insert_at_position(int pos, const T& element);
    void remove_first();
    void remove_last();
    void remove(const T& element);
    bool is_empty() ;
    void display(const T & );
    T* search(int id);
   void statictic ();
   void mergeSort();

    void  Sort();




};
#endif // CONTAINER_H


template <typename T>
Container<T>::Container() {
first=nullptr;
last=nullptr;
 count=0;

}

template <typename T>
Container<T>::~Container() {
    while (first != nullptr) {
        remove_first();
    }
}

template <typename T>
void Container<T>::insert_first(const T& element) {
    Node* newNode = new Node;
    newNode->item = element;
    if (count == 0) {
        first = last = newNode;
        newNode->next = newNode->prev = nullptr;
    } else {
        newNode->next = first;
        newNode->prev = nullptr;
        first->prev = newNode;
        first = newNode;
    }
    count++;
}



template <typename T>
void Container<T>::insert_last(const T& element) {
    Node* newNode = new Node;
    newNode->item = element;
    if (count == 0) {
        first = last = newNode;
        newNode->next = newNode->prev = nullptr;
    } else {
        newNode->next = nullptr;
        newNode->prev = last;
        last->next = newNode;
        last = newNode;
    }
    count++;
}

template <typename T>

void Container<T>::insert_at_position(int pos, const T& element) {
    if (pos < 0 || pos > count) {
      cout << "Error: Out of range." << endl;
        return;
    }

    if (pos == 0) {
        insert_first(element);
    } else if (pos == count) {
        insert_last(element);
    } else {
        Node* newNode = new Node;
        newNode->item = element;
        Node* curr = first;
        for (int i = 1; i < pos; i++) {
            curr = curr->next;
        }
        newNode->next = curr->next;
        newNode->prev = curr;
        curr->next->prev = newNode;
        curr->next = newNode;
        count++;
    }
}

template <typename T>
void Container<T>::remove_first() {
    if (count == 0) {
        cout << "The container is empty." << endl;
    } else if (count == 1) {
        delete first;
        first = last = nullptr;
        count = 0;
    } else {
        Node* curr = first;
        first = first->next;
        first->prev = nullptr;
        delete curr;
        count--;
    }
}

template <typename T>
void Container<T>::remove_last() {
    if (count == 0) {
       cout << "The container is empty." << endl;
    } else if (count == 1) {
        delete last;
        first = last = nullptr;
        count = 0;
    } else {
        Node* curr = last;
        last = last->prev;
        last->next = nullptr;
        delete curr;
        count--;
    }
}

template <typename T>
void Container<T>::remove(const T& element) {
    Node* curr = first;
    while (curr != nullptr) {
        if (curr->item == element) {
            if (curr == first) {
                remove_first();

            } else if (curr == last) {
                remove_last();

            } else {
                curr->prev->next = curr->next;
                curr->next->prev = curr->prev;
                delete curr;
                count--;

            }
        }
        curr = curr->next;
    }
}

template <typename T>
bool Container<T>::is_empty()  {
    return (first == nullptr);
}

template <typename T>
void Container<T>::display(const T & value)  {
    Node* curr = first;
    while (curr != nullptr) {
        cout << curr->item << " ";
        curr = curr->next;
    }
    cout << endl;
}

template <typename T>
T* Container<T>::search(int id) {
    Node* curr = first;
    while (curr != nullptr) {
        if (curr->item.get_number() == id) {
            return &(curr->item);
        }
        curr = curr->next;
    }
    return nullptr;
}
template <class T>
void Container<T>::Sort() {
    T* brr = new T[count];

    Node* curr = first;
    for (size_t i = 0; i < count; i++) {
        Node* mn = curr;
        Node* j = curr->next;
        while (j != nullptr) {
            if (j->item < mn->item)
                mn = j;
            j = j->next;
        }
        brr[i] = mn->item;
        curr = curr->next;
    }

    delete[] brr;
    first = curr;
}




