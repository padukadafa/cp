    #include <iostream>
    using namespace std;

    // membuat data manusia dengan properti nama,usia, pekerjaan,jenisKelamin
    struct Manusia {
        string nama;
        int usia;
        string pekerjaan;
        char jenisKelamin;
        // pointer mengarah ke singleLinkedList selanjutnya
        Manusia *next;
    };
    // Struct untuk Kumpulan data manusia
    struct ListManusia {
        Manusia *head;
        Manusia *tail;
    };
    // 2 list sesuai perintah
        ListManusia *List1 = new ListManusia();
        ListManusia *List2 = new ListManusia();

    // variabel untuk operasi, sengaja dibuat global biar nggak ribet buat lagi
    Manusia *tmp,*del;

    // fungsi untuk menambahkan data ke dalam head
    void insertFirst (ListManusia *listManusia,Manusia *manusia) {
        if (listManusia->head == NULL) {
            listManusia->head = manusia;
            listManusia->tail= manusia;
        } else {
            manusia->next = listManusia->head;
        listManusia->head = manusia;
        }
    }

    // fungsi untuk menambahkan data ke dalam tail
    void insertLast(ListManusia *listManusia,Manusia *manusia) {
        if (listManusia->head == NULL) {
            listManusia->head = manusia;
            listManusia->tail= manusia;
        } else {
            (listManusia->tail)->next = manusia;
            listManusia->tail = manusia;
        }
    }

    // menggabungkan dua list, urutannya [...first,...last];
    void combineList(ListManusia *first, ListManusia *last) {
        (first->tail)->next = last->head;
    }

    // fungsi untuk mengurutkan singlelinkedlist *gagal
    void shortList(ListManusia *list) {
        ListManusia *newList = new ListManusia();
        newList->head = list->head;
        tmp = list->head;
        Manusia *newTmp = newList->head;
        while(tmp->next != NULL) {
            newTmp = newList->head;
            while(newTmp != NULL) {
                if (tmp->usia > newTmp->usia) {
                    newTmp->next = tmp;
                    
                }
                cout << newTmp->nama << endl;
                newTmp = newTmp->next;
                
            }
            cout << tmp->nama << endl;
            tmp = tmp->next;
        }
    }
    // fungsi untuk mencetak single linked list
    void printList(ListManusia *list) {
        tmp = list->head;
        while(tmp != NULL) {
            cout << "Nama : " << tmp->nama << endl;
            cout << "Usia : " << tmp->usia << endl;
            cout << "Pekerjaan : " << tmp->pekerjaan << endl;
            tmp = tmp->next;
        }
    }

    // fungsi untuk menampilkan orang yang  sudah bekerja
    void manusiaSudahBekerja(ListManusia *list) {
        tmp = list->head;
        while(tmp != NULL) {
            // jika pekerjaan bukan pelajar dan mahasiswa maka akan di cetak
            if (tmp->pekerjaan != "Pelajar" && tmp->pekerjaan != "Mahasiswa") {
                cout << "Nama : " << tmp->nama << endl;
                cout << "Usia : " << tmp->usia << endl;
                cout << "Pekerjaan : " << tmp->pekerjaan << endl;
            
            }
            tmp = tmp->next;
        }
    }

    // fungsi untuk menampilkan orang yang belum bekerja
    void manusiaBelumBekerja(ListManusia *list) {
        tmp = list->head;
        while(tmp != NULL) {
            // jika pekerjaan sama dengan Pelajar atau Mahasiswa maka akan dicetak
            if (tmp->pekerjaan == "Pelajar" || tmp->pekerjaan == "Mahasiswa") {
                cout << "Nama : " << tmp->nama << endl;
                cout << "Usia : " << tmp->usia << endl;
                cout << "Pekerjaan : " << tmp->pekerjaan << endl;
            
            }
            tmp = tmp->next;
        }
    }

    void insertData() {

        cout << "Jumlah Keluarga 1 : ";
        // input jumlah data list pertama
        int n;cin >> n;
        for (int i =0; i <n;i++) {
            Manusia *manusia = new Manusia();
            getline(cin>>ws,manusia->nama);
            cin >> manusia->jenisKelamin;
            cin >> manusia->usia;
            getline(cin>>ws,manusia->pekerjaan);
            insertLast(List1,manusia);
        }
        cout << "Jumlah Keluarga 2 : ";
        // input jumlah data list kedua
        cin >> n;
        for (int i =0; i <n;i++) {
            Manusia *manusia = new Manusia();
            getline(cin>>ws,manusia->nama);
            cin >> manusia->jenisKelamin;
            cin >> manusia->usia;
            getline(cin>>ws,manusia->pekerjaan);
            insertLast(List2,manusia);
        }
    }
    void menu() {
        cout << "=================" << endl;
        cout << "a) insert data" << endl;
        cout << "b) combine data" << endl;
        cout << "c) print data" << endl;
        cout << "d) manusia sudah bekerja" << endl;
        cout << "e) manusia belum bekerja" << endl;
        cout << endl << endl;
        cout << "Pilih menu : ";
        char pilih;
        cin >> pilih;
        switch (pilih)
        {
        case 'a':
            insertData();
            menu();
            break;
        case 'b':
            combineList(List1,List2);
            menu();
        case 'c':
            printList(List1);
            menu();
        case 'd':
            manusiaSudahBekerja(List1);
            menu();
        case 'e':
            manusiaBelumBekerja(List1);
            menu();
        
        default:
            menu();
            break;
        }
    }

    int main() {
        menu();
    }