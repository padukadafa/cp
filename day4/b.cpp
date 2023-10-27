
#include <iostream>

using namespace std;

typedef int infotype;

typedef struct tElmtlist* address;
typedef struct tElmtlist {
    infotype info;
    address next;
} ElmtList;
typedef struct tList {
    address first;
} List;

void CreateEmpty(List* L) { (*L).first = NULL; }
bool IsEmpty(List L) { return L.first == NULL; }
address Allocation(infotype x) {
    address NewElmt;

    NewElmt = new ElmtList;
    NewElmt->info = x;
    NewElmt->next = NULL;

    return NewElmt;
}

void Deallocation(address hapus) { delete hapus; }

void InsertFirst(List* L, infotype x) {
    address NewElmt, tmp;

    NewElmt = Allocation(x);

    if (!IsEmpty(*L)) {
        NewElmt->next = (*L).first; // 1
        tmp = (*L).first;

        while (tmp->next != (*L).first) // 2
            tmp = tmp->next;

        tmp->next = NewElmt;  // 3
        (*L).first = NewElmt; // 4
    }
    else {
        (*L).first = NewElmt;       // 1
        NewElmt->next = (*L).first; // 2
    }
}

void InsertAfter(address PredElmt, infotype x) {
    address NewElmt;

    NewElmt = Allocation(x);

    NewElmt->next = PredElmt->next;
    PredElmt->next = NewElmt;
}

void InsertLast(List* L, infotype x) {
    address NewElmt, tmp;

    NewElmt = Allocation(x);

    if (!IsEmpty(*L)) {
        tmp = (*L).first;

        while (tmp->next != (*L).first) // 1
            tmp = tmp->next;

        // tmp->next = NewElmt; // 2
        // NewElmt->next = (*L).first; // 3
        InsertAfter(tmp, x);
    }
    else
        InsertFirst(L, x);
}

void DeleteFirst(List* L, infotype* hapus) {
    if (!IsEmpty(*L)) {
        address tmp1, tmp2;

        tmp1 = tmp2 = (*L).first;
        *hapus = tmp1->info;

        if (tmp1->next != (*L).first) {
            while (tmp2->next != (*L).first) // 1
                tmp2 = tmp2->next;

            (*L).first = (*L).first->next; // 2
            tmp2->next = (*L).first;       // 3
            tmp1->next = NULL;             // 4
        }
        else {
            tmp1->next = NULL; // 1
            (*L).first = NULL; // 2
        }

        Deallocation(tmp1);
    }
}

void DeleteAfter(address PredElmt, infotype* hapus) {
    if (PredElmt->next != NULL) {
        address tmp;

        tmp = PredElmt->next;
        *hapus = tmp->info;
        PredElmt->next = tmp->next;
        tmp->next = NULL;

        Deallocation(tmp);
    }
}

void DeleteLast(List* L, infotype* hapus) {
    if (!IsEmpty(*L)) {
        address predTmp, tmp;

        predTmp = NULL;
        tmp = (*L).first;
        *hapus = tmp->info;

        if (tmp->next != (*L).first) {
            while (tmp->next != (*L).first) { // 1
                predTmp = tmp;
                tmp = tmp->next;
            }

            // predTmp->next = (*L).first; // 2
            // tmp->next = NULL; // 3

            // Deallocation(tmp);
            DeleteAfter(predTmp, hapus);
        }
        else
            DeleteFirst(L, hapus);
    }
}

void InsertNumber(List* L, infotype x) {
    if (IsEmpty(*L) || x <= (*L).first->info)
        InsertFirst(L, x);
    else {
        address tmp;

        tmp = (*L).first;

        while (tmp->next != (*L).first) {
            if (x > tmp->info && x <= tmp->next->info)
                break;

            tmp = tmp->next;
        }

        InsertAfter(tmp, x);
    }
}

void DeleteNumber(List* L, infotype x) {
    if (!IsEmpty(*L)) {
        address predTmp, tmp;
        bool found;

        predTmp = NULL;
        tmp = (*L).first;
        found = false;

        while (tmp->next != (*L).first) {
            if (x == tmp->info) {
                found = true;

                break;
            }

            predTmp = tmp;
            tmp = tmp->next;
        }

        if (found || x == tmp->info)
            if (tmp == (*L).first)
                DeleteFirst(L, &x);
            else
                DeleteAfter(predTmp, &x);
        else
            cout << "Data " << x << " Tidak Tersimpan pada List" << endl;
    }
}

void Print(List L) {
    address tmp;

    tmp = L.first;

    while (tmp->next != L.first) {
        cout << "Data Elemen Ini: " << tmp->info << endl;
        cout << "Data Elemen Selanjutnya: " << tmp->next->info << endl;

        tmp = tmp->next;
    }

    cout << "Data Elemen Ini: " << tmp->info << endl;
    cout << "Data Elemen Selanjutnya: " << tmp->next->info << endl;
}

int main() {
    List data;
    int x;

    CreateEmpty(&data);

    /*
    InsertFirst(&data, 10);
    InsertLast(&data, 20);
    InsertFirst(&data, 100);
    InsertFirst(&data, 90);
    InsertLast(&data, 50);
    InsertLast(&data, 80);
    InsertFirst(&data, 40);
    InsertFirst(&data, 60);
    InsertLast(&data, 30);
    InsertFirst(&data, 70);

    DeleteFirst(&data, &x);
    cout << "Data yang Dihapus = " << x << endl;
    DeleteLast(&data, &x);
    cout << "Data yang dihapus = " << x << endl;
    */

    InsertNumber(&data, 8);
    InsertNumber(&data, 3);
    InsertNumber(&data, 6);
    InsertNumber(&data, 2);
    InsertNumber(&data, 1);
    InsertNumber(&data, 7);
    InsertNumber(&data, 5);
    InsertNumber(&data, 4);
    InsertNumber(&data, 9);

    DeleteNumber(&data, 5);
    DeleteNumber(&data, 9);
    DeleteNumber(&data, 1);

    InsertNumber(&data, 8);
    InsertNumber(&data, 3);
    InsertNumber(&data, 6);
    InsertNumber(&data, 2);
    InsertNumber(&data, 1);
    InsertNumber(&data, 7);
    InsertNumber(&data, 5);
    InsertNumber(&data, 4);
    InsertNumber(&data, 9);

    DeleteNumber(&data, 10);

    Print(data);

    return 0;
}
