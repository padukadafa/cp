#include <iostream>
using namespace std;

// perbedaan struct dan typedef

struct Mahasiswa {
    string nama;
    string nim;
};


int main() {
    Mahasiswa mahasiswa;
    cin >> mahasiswa.nama;
    cin >> mahasiswa.nim;

    cout << mahasiswa.nama << endl;
    cout << mahasiswa.nim << endl;

    

    return 0;
}