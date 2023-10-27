#include <iostream>
using namespace std;

struct Element {
    Element *NEXT;
    Element *prev;
    int info;
};
Element *head,*tail,*tmp;

void insertFirst(Element *element) {
    if (head == NULL) {
        head = element;
        tail = element;
        element->prev = element;
        element->NEXT = element;
        tail->NEXT = element;
        tail->prev = element;
    } else {
        element->NEXT = head;
        element->prev = tail;
        tail->NEXT = element;
        head= element;
    }
}
void insertLast(Element *element) {
    if (head == NULL) {
        head = element;
        tail = element;
        element->prev = element;
        element->NEXT = element;
        tail->NEXT = element;
        tail->prev = element;
    } else {
        element->NEXT = head;
        element->prev = tail;
        tail->NEXT = element;
        tail = element;
    }
}
void printElement() {
    tmp = head;
    if (head == NULL) {
        return;
    }
    do {
        cout << tmp->info << endl;
        tmp = tmp->NEXT;
    } while (tmp != head);
}

void deleteFirst() {
    tmp = head;
    head = tmp->NEXT;
    tail->NEXT = tmp->NEXT;
    delete tmp;    
}

void deleteLast() {
    tmp = head;
    while (tmp->NEXT != tail) {
        tmp = tmp->NEXT;
    }
    tmp->NEXT = head;
    delete tail;
    tail = tmp;
}

int main() {
    Element *Elmnt = new Element();
    Element *SecElmnt = new Element();
    Element *TElmnt = new Element();
    Elmnt->info = 7;
    SecElmnt->info = 9;
    TElmnt->info = 100;
    insertFirst(Elmnt);
    insertLast(SecElmnt);
    insertLast(TElmnt);
    deleteFirst();
    deleteLast();
    printElement();

}