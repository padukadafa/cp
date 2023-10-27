#include <iostream>
using namespace std;

#define print(F) cout << F
#define println(F) cout << F << endl
struct Element {
    int info;
    Element *next;
};
Element *tmp,*head,*tail,*del;

void addFirst(int info) {
    Element *newElmnt = new Element();
    newElmnt->info = info;
    if (head != NULL) {
        if (head->next ==NULL) {
            tail = head;
        }
        newElmnt->next = head;
    } else {
        newElmnt->next = NULL;
        tail = newElmnt;
    }
    head = newElmnt;
}
void addLast(int info) {
    Element *newElmnt = new Element();
    newElmnt->info = info;
    if (head == NULL) {
        head = newElmnt;
        tail = newElmnt;
    } else {
        if (tail != NULL) {
            tail->next = newElmnt;
        }
    }
    newElmnt->next = NULL;
    tail = newElmnt;
}

void insertAfter(Element *element) {
    tmp = head;
    while(tmp->next != element) {
        tmp = tmp->next;
    }
}

void insertElementFirst(Element *element) {
    if (head != NULL) {
        element->next = head;
        head = element;
    } else {
        head = element;
    }
}

void insertElementAfter(Element *element,Element *newElement) {
    tmp = head;
    newElement->next = tmp->next;
    tmp->next = newElement;

    
}
