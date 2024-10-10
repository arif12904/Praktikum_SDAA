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

// Fungsi untuk menampilkan data stack
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

// *** Implementasi Queue (CRUD berbasis Queue) ***
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

// Fungsi untuk menampilkan data queue
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
        cout << "9. Keluar\n";
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
                cout << "Keluar dari program.\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }
    } while (pilihan != 9);

    return 0;
}
