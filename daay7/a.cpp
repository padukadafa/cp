// catatan: kalau dari googlesheet input xyz123 setelah dienkripsi menjadi 123yzX. kalau seperti ini tidak akan bisa dienkripsi karena mengganti karakter secara langsung.
// jadi saya asumsikan kalau si X ini merupakan karakter yang dihide, jadi sebenarnya dia karakter pertama dari User yang diinput

#include <iostream>
using namespace std;


// membuat struct untuk setiap karakter di User
struct PassChar {
    // variabel untuk karakter
    char character;
    // reference untuk karakter selanjutnya
    PassChar *next;
    // reference untuk karakter sebelumnya
    PassChar *prev;
};
// membuat struct untuk menampung head dan tail User
struct User {
    // reference untuk head
    PassChar *head;
    string user;
    // reference untuk tail
    PassChar *tail;
};
// variabel pembantu
PassChar *tmp,*del;

// fungsi untuk manambahkan karakter baru di awal
void insertFirst(User *user, char character) {
    // membuat karakter User baru
    tmp = new PassChar();
    // memasukan nilai karakter dari properti fungsi
    tmp->character = character;

    // mengecek kondisi apakah head NULL
    if (user->head == NULL) {
        // menginiasiasi head dan tail dalam User jika head masih NULL
        user->head = tmp;
        user->tail = tmp;
    } else {
        // menggeser head kekanan dan mengisi head dengan karakter baru
        // menginisiasi properti next pada karakter baru menjadi head
        tmp->next = user->head;
        // menghubungkan properti prev pada head ke karakter baru
        user->head->prev = tmp;
        // mengubah head ke karakter baru
        user->head = tmp;
    }
}


// fungsi untuk menambahkan karakter baru pada list terakhir
void insertLast(User *user,char character) {
    // membuat karakter baru
    tmp = new PassChar();
    tmp->character = character;
    if (user->head == NULL) {
        // menginiasiasi head dan tail dalam User jika head masih NULL
        user->head = tmp;
        user->tail = tmp;
    } else {
        // menggatin prev karakter baru menjadi address tail
        tmp->prev = user->tail;
        // mengganti next tail yang sekarang menjadi address karakter baru
        user->tail->next = tmp;
        // mengganti tail menjadi karakter baru
        user->tail = tmp;
    }
}

void printPassword(User *user) {
    // menyimpan sementara head;
    tmp = user->head;
    // jika tmp tidak null maka looping akan terus dijalankan
    while(tmp->next != NULL) {
        // mencetak karakter dari tmp
        cout << tmp->character;
        // mengganti tmp menjadi address selanjutnya
        tmp = tmp->next;
    }
    // fungsi untuk menghide karakter terakhir
    cout << "X" << endl;
    cout << endl;
}

void printReversedPassword(User *user) {
    tmp = user->tail;
    
    while(tmp->prev != NULL) {
        cout << tmp->character;
        tmp = tmp->prev;
    }
    cout << "X";
    cout << endl;
}

void encrypt(User *user) { // p@ssw0 -> @sswpX
    PassChar *newChar = new PassChar();
    PassChar *newChars = new PassChar();
    // fungsi untuk menghapus karakter pertama dari User dan menyimpannya di variabel tmp
    newChar = user->head;
    newChars = user->tail;
    user->head->next->prev = NULL;
    user->head = user->head->next;
    user->tail->prev->next = NULL;
    user->tail = user->tail->prev;
    insertLast(user,newChar->character);
    insertLast(user,newChars->character);

}

void decrypt(User *user) {
    PassChar *newChar = new PassChar();
    // fungsi untuk menghapus karakter terakhir dari User yang terenkripsi dan menyimpannya di variabel tmp
    newChar = user->tail;
    newChar->prev->next = NULL;
    user->tail = newChar->prev;
    // fungsi untuk memindahkan 3 karakter pertama ke belakang
    tmp = user->head;
    user->tail->next = tmp;
    user->head->prev = user->tail;
    tmp->next->next->next->prev = NULL;
    user->head = tmp->next->next->next;
    tmp->next->next->next = NULL;
    user->tail = tmp->next->next;
    // menambahkan karakter tail yang telah disimpan ke head
    insertFirst(user,newChar->character);
}


// add user
void createUser(User *newUser,string name,string pass) {
    for (char x : pass) {
        insertLast(newUser,x);
    }
    // mengenkripsi User
    encrypt(newUser);
}

int main() {
    // membuat User baru
    User *adminUser = new User;
    createUser(adminUser,"admin","p@ssw0"); // xyz23X
    printPassword(adminUser);
    decrypt(adminUser);
    printReversedPassword(adminUser); // X23xyz
    
    string user;
    cin >> user;
    if (user == "admin") {
        printPassword(adminUser);
    }
    if (user == "anonymous") {
        printReversedPassword(adminUser);
    }
    
    return 0;
}