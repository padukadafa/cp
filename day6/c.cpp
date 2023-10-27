#include <iostream>
using namespace std;

struct PasswordChar {
    char character;
    PasswordChar *next;
    PasswordChar *prev;
};

struct PasswordList {
    PasswordChar *head;
    PasswordChar *tail;
};

PasswordChar *tmp,*del;

void insertLast(PasswordList *list,char character) {
    PasswordChar *newChar = new PasswordChar;
    newChar->character = character;
    if (list->head == NULL) {
        list->head =newChar;
        list->tail = newChar;
    } else {
        newChar->prev = list->tail;
        list->tail->prev = newChar;
        list->tail = newChar;
    }
}

void encrypt(PasswordList *list) {
    tmp = list->head;
    list->head = list->head->next->next->next;
    list->head->prev = NULL;
    list->tail->next = tmp;
    list->tail = tmp->next->next;
}

void printPassword(PasswordList *list) {
    tmp = list->head;
    while(tmp != NULL) {
        cout << tmp->character;
        tmp = tmp->next;
    }
    cout << endl;
}

int main() {
    string password;
    PasswordList *passwordList;
    cin >> password;
    for (int i =0;i < password.length();i++) {
        insertLast(passwordList,password[i]);
    }
    encrypt(passwordList);
    printPassword(passwordList);

}