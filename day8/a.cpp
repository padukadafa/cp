#include<iostream>
using namespace std;

struct Element {
    int info;
    Element *next;
    Element *prev;
};

struct ElementList {
    Element *head;
    Element *tail;
};

void insertAfter(ElementList *list,Element *element,int info) {
    Element *newElement = new Element;
    newElement->info = info;
    if (list->head == NULL) {
        cout << "List masih kosong" << endl;
        return;
    }
    Element *tmp = list->head;
    while(tmp != NULL) {
        if (tmp == list->tail) {
            cout << "Element tidak ditemukan";
            return;
        }
        if (tmp == list->tail) {
            tmp = NULL;
        } else {
            tmp = tmp->next;
        }
        
    }
    newElement->next = element->next;
    newElement->prev = element;
    element->next = newElement;
    newElement->next->prev = newElement;
    if (element == list->tail) {
        list->tail = newElement;
    }
    if (element == list->head) {
        list->head = newElement;
    }
}
void insertFirst(ElementList *list,int info) {
    
    Element *newElement = new Element;
    newElement->info = info;
    
    if (list->head == NULL) {
        newElement->next = newElement;
        newElement->prev = newElement;
        list->head = newElement;
        list->tail = newElement;
    }
    Element *element = list->head;
    
    newElement->next = element->next;
    newElement->prev = element;
    list->head = newElement;
}
void insertLast(ElementList *list,int info) {
    Element *newElement = new Element;
    Element *element = list->tail;
    newElement->info = info;
    if (list->head == NULL) {
        newElement->next = newElement;
        newElement->prev = newElement;
        list->head = newElement;
        list->tail = newElement;
    }
    newElement->next = element->next;
    newElement->prev = element;
    list->tail = newElement;
}

void deleteElement(ElementList *list,Element *element) {
    
    if (element->next == NULL || element->prev == NULL) {
        cout << "Element tidak valid" << endl;
        return;
    }
    if (list->head == element) {
        element->next->prev = element->prev;
        element->prev->next = element->next;
        list->head = element->next;
        delete element;
        return;
    }
    if (list->tail == element) {
        element->next->prev = element->prev;
        element->prev->next = element->next;
        list->tail = element->next;
        delete element;
        return;
    }
    element->next->prev = element->prev;
    element->prev->next = element->next;
}


void deleteFirst(ElementList *list) {
    Element *element = list->head;
    element->next->prev = element->prev;
    element->prev->next = element->next;
    list->head = element->next;
    delete element;
}
void deleteLast(ElementList *list) {
    Element *element = list->tail;
    element->next->prev = element->prev;
    element->prev->next = element->next;
    list->tail = element->next;
    delete element;
}

void promtInsertMany(ElementList *list);
void promtInsertFirst(ElementList *list);
void promtInsertLast(ElementList *list);
void promtInsertAfter(ElementList *list);

void printList(ElementList *list) {
    Element *tmp = list->head;

    while(tmp != list->tail->next) {
        cout << tmp->info << endl;
        tmp = tmp->next;
        
    }
}

void menu() {
    ElementList *list;
    int opt;
    cout << "====================================" << endl;
    cout << " 0. Insert Banyak " << endl;
    cout << " 1. Insert First" << endl;
    cout << " 2. Insert Last" << endl;
    cout << " 3. Inser After" << endl;
    cout << " 4. Delete First" << endl;
    cout << " 5. Delete Last" << endl;
    cout << " 6. Delete After" << endl;
    cout << " 7. Print List" << endl;
    cout << endl << endl;
    cout << " :=> "; cin >> opt;

    switch (opt)
    {
    case 0:
        promtInsertMany(list);
        break;
    case 1:
        promtInsertFirst(list);
        break;
    case 2:
        promtInsertLast(list);
        break;
    case 3:
        promtInsertAfter(list);
        break;
    case 4:
        deleteFirst(list);
        break;
    case 5:
        deleteLast(list);
    case 6:
        break;
    case 7:
        printList(list);
        break;

    
    default:
        cout << "Out of index" << endl;
        menu();
        break;
    }
}

void promtInsertFirst(ElementList *list) {
    int val;
    cout << " Value : "; cin >> val;
    insertFirst(list,val);
    menu();
}
void promtInsertMany(ElementList *list) {
    int val;
    while(val != -1) {
        cin >> val;
        insertFirst(list,val);
    }
    menu();
}
void promtInsertLast(ElementList *list) {
    int val;
    cout << " Value : "; cin >> val;
    insertFirst(list,val);
    menu();
}
void promtInsertAfter(ElementList *list) {
    int val,index,selectedIndex,count =0;
    Element *tmp = list->head;

    while( tmp != NULL) {
        cout << " " << index << ". " << tmp->info << endl;
        count++;
        if (tmp != list->tail) {
            tmp = tmp->next;
        } else {
            tmp = NULL;
        }
    }
    cout << " Pilih nomor : "; cin >>selectedIndex;
    if (selectedIndex > count || selectedIndex < count) {
        cout << "Out of index !" << endl;
        menu();
        return;
    };
    tmp = list->head;
    index = 1;
    while(count != selectedIndex) {
        tmp = tmp->next;
        index++;
    }
    cout << " Value : "; cin >> val;
    insertAfter(list,tmp,val);
    menu();
}

int main() {
    menu();
    return 0;
}