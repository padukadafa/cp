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


void remove(Element *element) {
    tmp = head;
    while(tmp->next != element) {
        tmp = tmp->next;
    }
    tmp->next = element->next;
    delete element;
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


void insertAfter(Element *element,int info) {
    tmp = head;
    element->info = info;
    while(tmp->next != NULL && tmp->next != element) {
        tmp = tmp->next;
    }
    element->next = tmp->next;
    tmp->next = 
    element;
}

void removeAfter(Element *element) {
    tmp = element->next;
    if (element->next != NULL) {
        element->next = tmp->next;
        delete tmp;
    }
}

void removeByInfo(int info) {
    del = head;
    while(del->next != NULL) {
        
        if (del->info == info) { 
            break;
        }
        tmp = del;
        del = del->next;
    }
    // if (tmp->next == del) {
    //     println("Ketemu coy");
    // }
    // tmp->next = del->next;
    
    // if (del->info == info) {
    //     delete del;
    // }
}

void printList() {
    tmp = head;
    while(tmp!= NULL) {
        println(tmp->info);
        tmp = tmp->next;
    }
}

int main() {
    Element *element = new Element();
    element->info = 87;
    Element *newElement = new Element();
    newElement->info = 9812;
    
    addLast(32);
    addFirst(12);
    addFirst(72);
    insertElementFirst(element);
    insertElementAfter(element,newElement);
    removeAfter(newElement);
    addLast(61);
    addLast(65);
    
    printList();
    return 0;
}