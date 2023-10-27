#include <iostream>
using namespace std;

struct Data {
    int info;
    Data *next;
    Data *prev;
};

Data *head,*tail,*tmp,*del;

void insertFirst(int info) {
    Data *newData = new Data;
    newData->info = info;
    if (head == NULL) {
        head = newData;
        tail = newData;
    } else {

        newData->next = head;
        head->prev = newData;
        head = newData;
    }
}

void printData() {
    tmp= head;
    while(tmp->next != NULL) {
        
        cout << tmp->info << endl;
        tmp = tmp->next->next;
        
    }
    tmp = tail;
    while(tmp != NULL) {
        cout << tmp->info << endl;
        tmp = tmp->prev;
    }
}
int main() {
    for (int i =5;i > 0;i--) {
        insertFirst(i);
    }
    printData();
    return 0;
}