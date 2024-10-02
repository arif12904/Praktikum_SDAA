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

Tas* head = nullptr;  

void tambahTas() {
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
    
    newTas->next = head;  
    head = newTas;

    cout << "Tas berhasil ditambahkan!\n";
}

void tampilkanTas() {
    if (head == nullptr) {
        cout << "Belum ada data tas.\n";
        return;
    }

    Tas* current = head;
    while (current != nullptr) {
        cout << "ID: " << current->id << "\n";
        cout << "Nama: " << current->nama << "\n";
        cout << "Stok: " << current->stok << "\n";
        cout << "Harga: " << current->harga << "\n";
        current = current->next;
    }
}

void updateTas() {
    int id;
    cout << "Masukkan ID Tas yang ingin diupdate: ";
    cin >> id;
    
    Tas* current = head;
    while (current != nullptr) {
        if (current->id == id) {
            cout << "Masukkan Nama Tas Baru: ";
            cin.ignore();  
            getline(cin, current->nama);
            
            cout << "Masukkan stok Tas Baru: ";
            cin >> current->stok;
            
            cout << "Masukkan Harga Tas Baru: ";
            cin >> current->harga;
            
            cout << "Tas berhasil diupdate!\n";
            return;
        }
        current = current->next;
    }

    cout << "Tas dengan ID tersebut tidak ditemukan.\n";
}

void hapusTas() {
    int id;
    cout << "Masukkan ID Tas yang ingin dihapus: ";
    cin >> id;

    if (head == nullptr) {
        cout << "Belum ada data tas untuk dihapus.\n";
        return;
    }

    if (head->id == id) {
        Tas* temp = head;
        head = head->next;
        delete temp;
        cout << "data tas berhasil dihapus!\n";
        return;
    }

    Tas* current = head;
    while (current->next != nullptr) {
        if (current->next->id == id) {
            Tas* temp = current->next;
            current->next = current->next->next;
            delete temp;
            cout << "Data tas berhasil dihapus!\n";
            return;
        }
        current = current->next;
    }

    cout << "Data tas dengan ID tersebut tidak ditemukan.\n";
}

int main() {
    int pilihan;

    do {
        cout << "\nMenu Pendataan Toko Tas\n";
        cout << "1. menambahkah data Tas\n";
        cout << "2. menampilkan data Tas\n";
        cout << "3. meng-Update data Tas\n";
        cout << "4. mengHapus data Tas\n";
        cout << "5. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tambahTas();
                break;
            case 2:
                tampilkanTas();
                break;
            case 3:
                updateTas();
                break;
            case 4:
                hapusTas();
                break;
            case 5:
                cout << "Keluar dari program.\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }
    } while (pilihan != 5);

    return 0;
}
