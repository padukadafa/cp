#include <iostream>
using namespace std;

#define print(F) cout << F
#define println(F) cout << F << endl
struct Element {
    int info;
    string address; 
    Element *next;
    Element *prev;
};
Element *tmp,*head,*tail;

void addLast(int info,string address) {
    Element *element = new Element();
    element->info = info;
    element->address = address;
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
void newElement(int info,string address) {
    Element *element = new Element();
    element->info = info;
    element->address = address;
    element->next = NULL;
    element->prev = NULL;
    head = element;
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
        print(tmp);
        print(" : ");
        println(tmp->info);
        tmp = tmp->next;
    }
}
void soal() {
    tmp = head;
    cout << ((tmp->next)->prev)->info << endl;
    println(((((tmp->next)->prev)->next)->next)->address);
    println((((((((tmp->next)->prev)->next)->prev)->next)->prev)->next)->info);
    tmp = ((((tmp->next)->next)->prev)->next)->prev;
    cout << tmp->info << endl;
    cout << ((tmp->next)->prev)->address << endl;
}
int main() {
    newElement(7,"0xebbf30");
    addLast(4,"0x123f10");
    addLast(8,"0x1a91efd0");
    addLast(2,"0xdefed0");
    addLast(9,"f0x12beeb0");
    println("\n\n\n");
    soal();
}