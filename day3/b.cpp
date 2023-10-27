#include <iostream>
using namespace std;

#define print(F) cout << F
#define println(F) cout << F << endl
struct Element {
    int info;
    Element *next;
    Element *prev;
};
Element *tmp,*head,*tail;

void addLast(int info) {
    Element *element = new Element();
    element->info = info;
    if (tail != NULL) {
        element->prev = tail;
        tail->next = element;
    } else {
        head->next = element;
        element->prev = head;
    }
    
    element->next = NULL;
    
    tail = element;
}

void addShorted(int info) {
    Element *element = new Element();
    element->info = info;
    tmp = head;
    while(tmp !=NULL) {
        if (tmp->info > info) {
            if (tmp->prev!= NULL) {
                element->prev = tmp->prev;
                (tmp->prev)->next = element;
            } else {
                element->prev = NULL;
            }
            tmp->prev = element;
            element->next = tmp;
            
            return;
        }
        tmp = tmp->next;
    }
    if (tmp->prev!= NULL) {
        element->prev = tmp->prev;
        (tmp->prev)->next = element;
    } else {
        element->prev = NULL;
    }
    tmp->prev = element;
    element->next = tmp;
}

void newList(int info) {
    Element *element = new Element();
    element->info = info;
    element->next = NULL;
    element->prev = NULL;
    head = element;
}

void remove(Element *element) {
    tmp  = element->prev;
    tmp->next = element->next;
    (element->next)->prev=element->prev;
    delete element;
}

void printAddress() {
    tmp = head;
    while(tmp !=NULL) {
        println(tmp);
        tmp = tmp->next;
    }
}

void printElement() {
    tmp = head;
    while(tmp !=NULL) {
        println(tmp->info);
        tmp = tmp->next;
    }
}

int main() {
    newList(7);
    addShorted(9);
    addShorted(4);
    addShorted(8);
    addShorted(9);
    printElement();
    return 0;

}