#include <iostream>
#include <string>

using namespace std;

struct Tas {
    int id;
    string nama;
    int stok;
    float harga;
    Tas* next;  
};

Tas* stack = nullptr;  
Tas* queuehead = nullptr; 
Tas* queueRear = nullptr;  


void pushTas() {
    Tas* newTas = new Tas;
    
    cout << "Masukkan ID Tas: ";
    cin >> newTas->id;
    cin.ignore();
    
    cout << "Masukkan Nama Tas: ";
    getline(cin, newTas->nama);
    
    cout << "Masukkan stok Tas: ";
    cin >> newTas->stok;
    
    cout << "Masukkan Harga Tas: ";
    cin >> newTas->harga;
    
    newTas->next = stack;  
    stack = newTas;

    cout << "Tas berhasil ditambahkan ke stack!\n";
}

void popTas() {
    if (stack == nullptr) {
        cout << "Stack kosong.\n";
        return;
    }

    Tas* temp = stack;
    stack = stack->next;
    delete temp;

    cout << "Tas berhasil di-pop dari stack.\n";
}

void updateTasStack() {
    int id;
    cout << "Masukkan ID Tas yang ingin diupdate di Stack: ";
    cin >> id;

    Tas* current = stack;
    while (current != nullptr) {
        if (current->id == id) {
            cout << "Masukkan Nama Tas Baru: ";
            cin.ignore();  
            getline(cin, current->nama);
            
            cout << "Masukkan stok Tas Baru: ";
            cin >> current->stok;
            
            cout << "Masukkan Harga Tas Baru: ";
            cin >> current->harga;
            
            cout << "Tas berhasil diupdate di Stack!\n";
            return;
        }
        current = current->next;
    }

    cout << "Tas dengan ID tersebut tidak ditemukan di Stack.\n";
}

void tampilkanStack() {
    if (stack == nullptr) {
        cout << "Stack kosong.\n";
        return;
    }

    Tas* current = stack;
    cout << "Data dalam Stack:\n";
    while (current != nullptr) {
        cout << "ID: " << current->id << "\n";
        cout << "Nama: " << current->nama << "\n";
        cout << "Stok: " << current->stok << "\n";
        cout << "Harga: " << current->harga << "\n";
        current = current->next;
    }
}

void enqueueTas() {
    Tas* newTas = new Tas;

    cout << "Masukkan ID Tas: ";
    cin >> newTas->id;
    cin.ignore();

    cout << "Masukkan Nama Tas: ";
    getline(cin, newTas->nama);

    cout << "Masukkan stok Tas: ";
    cin >> newTas->stok;

    cout << "Masukkan Harga Tas: ";
    cin >> newTas->harga;

    newTas->next = nullptr;

    if (queueRear == nullptr) {
        queuehead = queueRear = newTas;
    } else {
        queueRear->next = newTas;
        queueRear = newTas;
    }

    cout << "Tas berhasil ditambahkan ke queue!\n";
}

void dequeueTas() {
    if (queuehead == nullptr) {
        cout << "Queue kosong.\n";
        return;
    }

    Tas* temp = queuehead;
    queuehead = queuehead->next;

    if (queuehead == nullptr) {
        queueRear = nullptr;
    }

    delete temp;
    cout << "Tas berhasil di-dequeue.\n";
}

void updateTasQueue() {
    int id;
    cout << "Masukkan ID Tas yang ingin diupdate di Queue: ";
    cin >> id;

    Tas* current = queuehead;
    while (current != nullptr) {
        if (current->id == id) {
            cout << "Masukkan Nama Tas Baru: ";
            cin.ignore();  
            getline(cin, current->nama);
            
            cout << "Masukkan stok Tas Baru: ";
            cin >> current->stok;
            
            cout << "Masukkan Harga Tas Baru: ";
            cin >> current->harga;
            
            cout << "Tas berhasil diupdate di Queue!\n";
            return;
        }
        current = current->next;
    }

    cout << "Tas dengan ID tersebut tidak ditemukan di Queue.\n";
}

void tampilkanQueue() {
    if (queuehead == nullptr) {
        cout << "Queue kosong.\n";
        return;
    }

    Tas* current = queuehead;
    cout << "Data dalam Queue:\n";
    while (current != nullptr) {
        cout << "ID: " << current->id << "\n";
        cout << "Nama: " << current->nama << "\n";
        cout << "Stok: " << current->stok << "\n";
        cout << "Harga: " << current->harga << "\n";
        current = current->next;
    }
}


Tas* partition(Tas* low, Tas* high) {
    float pivot = high->harga;
    Tas* i = low;

    for (Tas* j = low; j != high; j = j->next) {
        if (j->harga < pivot) {
            swap(i->harga, j->harga);
            swap(i->id, j->id);
            swap(i->nama, j->nama);
            swap(i->stok, j->stok);
            i = i->next;
        }
    }
    swap(i->harga, high->harga);
    swap(i->id, high->id);
    swap(i->nama, high->nama);
    swap(i->stok, high->stok);
    return i;
}

void quickSortAsc(Tas* low, Tas* high) {
    if (low != nullptr && high != nullptr && low != high && low != high->next) {
        Tas* p = partition(low, high);
        quickSortAsc(low, p);
        quickSortAsc(p->next, high);
    }
}

void quickSortStack() {
    Tas* tail = stack;
    while (tail->next != nullptr) {
        tail = tail->next;
    }
    quickSortAsc(stack, tail);
    cout << "Stack berhasil diurutkan secara ascending berdasarkan harga!\n";
}

Tas* sortedMergeDesc(Tas* a, Tas* b) {
    if (!a)
        return b;
    if (!b)
        return a;

    if (a->harga > b->harga) {
        a->next = sortedMergeDesc(a->next, b);
        return a;
    } else {
        b->next = sortedMergeDesc(a, b->next);
        return b;
    }
}

void split(Tas* source, Tas** front, Tas** back) {
    Tas* fast = source->next;
    Tas* slow = source;

    while (fast != nullptr) {
        fast = fast->next;
        if (fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *front = source;
    *back = slow->next;
    slow->next = nullptr;
}

void mergeSortDesc(Tas** headRef) {
    Tas* head = *headRef;
    if (head == nullptr || head->next == nullptr) {
        return;
    }

    Tas* front;
    Tas* back;

    split(head, &front, &back);

    mergeSortDesc(&front);
    mergeSortDesc(&back);

    *headRef = sortedMergeDesc(front, back);
}

void sortQueueDesc() {
    mergeSortDesc(&queuehead);
    cout << "Queue berhasil diurutkan secara descending berdasarkan harga!\n";
}

int main() {
    int pilihan;

    do {
        cout << "\nMenu Pendataan Toko Tas Berbasis Stack dan Queue\n";
        cout << "1. Push Tas ke Stack\n";
        cout << "2. Pop Tas dari Stack \n";
        cout << "3. Update Tas di Stack\n";
        cout << "4. Tampilkan Stack\n";
        cout << "5. Enqueue Tas ke Queue\n";
        cout << "6. Dequeue Tas dari Queue\n";
        cout << "7. Update Tas di Queue\n";
        cout << "8. Tampilkan Queue\n";
        cout << "9. Urutkan Stack berdasarkan harga (Quick Sort Asc)\n";
        cout << "10. Urutkan Queue berdasarkan harga (Merge Sort Desc)\n";
        cout << "11. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                pushTas();
                break;
            case 2:
                popTas();
                break;
            case 3:
                updateTasStack();
                break;
            case 4:
                tampilkanStack();
                break;
            case 5:
                enqueueTas();
                break;
            case 6:
                dequeueTas();
                break;
            case 7:
                updateTasQueue();
                break;
            case 8:
                tampilkanQueue();
                break;
            case 9:
                quickSortStack();
                break;
            case 10:
                sortQueueDesc();
                break;
            case 11:
                cout << "Keluar dari program.\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }
    } while (pilihan != 11);

    return 0;
}
