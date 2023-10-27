#include <iostream>
using namespace std;

// membuat tipe data single linked list mahasiswa yang berisi data nama,nim,kelas,nilai dan next
struct Mahasiswa {
    string nama;
    string nim;
    string kelas;
    int nilai;
    Mahasiswa *next;
};

// membuat variabel referensi
Mahasiswa *head,*tail,*tmp,*del;

// fungsi untuk memasukan data mahasiswa pada head single linked list
void insertFirst(Mahasiswa *mahasiswa) {
    // jika head kosong atau belum ada data di single linked list. maka otomatis data yang baru menjadi head dan tail
    if (head == NULL) {
        mahasiswa->next = NULL;
        head = mahasiswa;
        tail = mahasiswa;
        
    } else {
        mahasiswa->next = head;
        head = mahasiswa;
    }
}

// fungsi untuk memasukan data mahasiswa pada tail single linked list
void insertLast(Mahasiswa *mahasiswa) {
    // jika head kosong atau belum ada data di single linked list. maka otomatis data yang baru menjadi head dan tail
    if (head == NULL) {
        head = mahasiswa;
        tail = mahasiswa;
    } else {
        tail->next = mahasiswa;
        tail = mahasiswa;
    }
}

// fungsi untuk menghitung jumlah data pada singlelinkedlist;
int countSingleLinkedList() {
    tmp = head;
    int count = 0;
    // jika tmp tidak null maka tmp akan diubah menjadi tmp->next
    while(tmp != NULL) {
        count++;
        tmp = tmp->next;
    }
    return count;
}


// fungsi untuk memasukan data ke tengah single linked list
void insertCenter(Mahasiswa *mahasiswa) {
    // mendapatkan jumlah singlelinkedlist
    int count = countSingleLinkedList();

    int center = count/2;
    tmp = head;
    // looping untuk mencari data di tengah
    for (int i =0;i < center-1;i++) {
        tmp = tmp->next;
    }
    
    mahasiswa->next = tmp->next;
    tmp->next = mahasiswa;

}

// fungsi untuk menampilkan semua data pada single linked list
void printSingeLinkedList() {

    tmp = head;
    while(tmp!=NULL) {
        cout << "==================================" << endl;
        cout << "Nama : " << tmp->nama << endl;
        cout << "NIM : " << tmp->nim << endl;
        cout << "Kelas : " << tmp->kelas << endl;
        cout << "Nilai : " << tmp->nilai << endl;
        
        tmp = tmp->next;
    }
}

// fungsi untuk mendapatkan nilai berdasarkan nim
int getNilai(string nim) {
    tmp = head;
    while(tmp!=NULL) {
        // jika nilai tmp->nim sudah sesuai dengan nim yang ingin dicari, maka fungsi akan mengeluarkan integer 0
        if (nim == tmp->nim) {
            return tmp->nilai;

        }
        tmp = tmp->next;
    }
    // jika nim tidak ada akan mengeluarkan nilai 0
    return 0;

}


// fungsi untuk menghapus data mahasiswa pada single linked list
void deleteMahasiswa(Mahasiswa *mahasiswa) {
    tmp = head;
    if (mahasiswa == head) {
        head = head->next;
    }
    while(tmp->next != mahasiswa) {
        tmp = tmp->next;
    }
    tmp->next = mahasiswa->next;
    delete mahasiswa;
}

// fungsi untuk menghapus data mahasiswa dengan nilai dibawah 50
void yaHapus() {
    tmp = head;
    while(tmp != NULL) {
        del = tmp;
        tmp = tmp->next;
        // jika nilai kurang dari 50 maka data akan dihapus
        if (del->nilai < 50) {
            
            deleteMahasiswa(del);
        }
        
    }

}


// fungsi untuk mengurutkan data nilai single linked list
void shortedSingleLinkedList() {
    int n = countSingleLinkedList();
    int nilai[n],i=0;
    tmp = head;
    while(tmp!=NULL) {
        nilai[i] = tmp->nilai;
        tmp = tmp->next;
        i++;
    }
    for(int j = 0;j < n;j++) {
        for (int k =j;k <n;k++) {
            if (nilai[j] < nilai[k]) {
                int temp = nilai[j];
                nilai[j] = nilai[k];
                nilai[k] = temp;
            }
        }
    }
    // fungsi untuk menampilkan nilai yang telah diurutkan
    for (int s : nilai) {
        cout << s << endl;
    }

}


// fungsi untuk mmasukan data ke single linked list
void insertData() {
    int n;
    cout << "Count : ";
    cin >> n;
    for (int i =0;i < n;i++) {
        cout << "====== data " << i+1 << "=======" << endl;
        Mahasiswa *mahasiswa = new Mahasiswa();
        cout << "Nama : ";
        getline(cin>>ws,mahasiswa->nama);
        cout << "Kelas : ";
        cin >> mahasiswa->kelas;
        cout << "NIM : ";
        cin >> mahasiswa->nim;
        cout << "Nilai : ";
        cin >> mahasiswa->nilai;
        insertFirst(mahasiswa);
    }
}


// fungsi untuk menampilkan menu
void menu() {
    string nim;
    Mahasiswa *mahasiswa = new Mahasiswa();
    char opt;
    cout << "========================" << endl;
    cout << "a) insert data" << endl;

    cout << "b) show all data" << endl;
    cout << "c) delete data where nilai less then 50" << endl;
    cout << "d) show shorted nilai" << endl;
    cout << "e) search data by nim" << endl;
    cout << "f) insert center" << endl;
    cout << endl;
    cout << "select option -> ";
    cin >> opt;
    switch (opt)
    {
    case 'a':
        insertData();
        menu();
        
        break;
    case 'b':
        printSingeLinkedList();
        menu();
        break;
    case 'c':
        yaHapus();
        menu();
    case 'd':
        shortedSingleLinkedList();
        menu();
    case 'e':
        
        cout << "NIM : ";
        cin >> nim;
        getNilai(nim);
        menu();
    case 'f':
        
        cout << "Nama : ";
        getline(cin>>ws,mahasiswa->nama);
        cout << "Kelas : ";
        cin >> mahasiswa->kelas;
        cout << "NIM : ";
        cin >> mahasiswa->nim;
        cout << "Nilai : ";
        cin >> mahasiswa->nilai;
        insertCenter(mahasiswa);
        menu();
        
    default:
        cout << "Wrong input!" <<endl;
        menu();
        break;
    }
}

// fungsi main
int main() {
    menu();
    
}