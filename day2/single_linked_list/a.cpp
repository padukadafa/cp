#include <iostream>
using namespace std;

struct BUKU {
    string judul,pengarang;
    int tahunTerbit;
    BUKU *next;
};

BUKU *head,*cur,*tail,*temp,*del;


void add(string judul,string pengarang, int tahunTerbit) {
    head = new BUKU();
    head->judul = judul;
    head->pengarang = pengarang;
    head->tahunTerbit = tahunTerbit;
    head->next = NULL;
    tail = head;
}

void addFirst(string judul,string pengarang, int tahunTerbit) {
    temp = new BUKU();
    temp->judul = judul;
    temp->pengarang = pengarang;
    temp->tahunTerbit = tahunTerbit;
    if (head != NULL ) {
        temp->next = head;
    }

    head = temp;
}

void addLast(string judul,string pengarang, int tahunTerbit) {
    temp = new BUKU();
    temp->judul = judul;
    temp->pengarang = pengarang;
    temp->tahunTerbit = tahunTerbit;
    temp->next = NULL;
    tail->next = temp;
    tail = temp;

}
void deleteL(int num) {
    temp = head;
    int i =0;
    if (num == 0) {
        head = temp->next;
        delete temp;
        return;
    }
    while(i < num-1){
        temp = temp->next;
        i++;
    }
    del = temp->next;
    temp->next = del->next;
    delete del;
}
void printSingleLinkedList() {
    cur = head;

    while(cur != NULL) {
        cout << "Judul Buku : " << cur->judul << endl;
        cout << "Pengarang : " << cur->pengarang << endl;
        cout << "Tahun Terbit : " << cur->tahunTerbit << endl;
        cur = cur->next;
    }
}

int main() {
    add("Semenjak asd a","Budi laskasdsao",2016);
    
    addFirst("Jatuh Cinta","Budi do",2014);
    
    addLast("Semenjak","Budi lasko",2016);printSingleLinkedList();cout << "\n\n";
    deleteL(0);
    printSingleLinkedList();
    
    return 0;

}