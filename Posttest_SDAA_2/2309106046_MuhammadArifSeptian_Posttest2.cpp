#include <iostream>
#include <string>

using namespace std;

struct Tas {
    int id;
    string nama;
    int stok;
    float harga;
};


void tambahTas(Tas tas[], int &jumlahTas) {
    cout << "Masukkan ID Tas: ";
    cin >> tas[jumlahTas].id;
    cin.ignore();  
    
    cout << "Masukkan Nama Tas: ";
    getline(cin, tas[jumlahTas].nama);
    
    cout << "Masukkan stok Tas: ";
    cin >> tas[jumlahTas].stok;
    
    cout << "Masukkan Harga Tas: ";
    cin >> tas[jumlahTas].harga;
    
    jumlahTas++;
    cout << "Tas berhasil ditambahkan!\n";
}


void tampilkanTas(const Tas tas[], int jumlahTas) {
    if (jumlahTas == 0) {
        cout << "Belum ada data tas.\n";
        return;
    }
    
    for (int i = 0; i < jumlahTas; i++) {
        cout << "ID: " << tas[i].id << "\n";
        cout << "Nama: " << tas[i].nama << "\n";
        cout << "Stok: " << tas[i].stok << "\n";
        cout << "Harga: " << tas[i].harga << "\n";
    }
}

void updateTas(Tas tas[], int jumlahTas) {
    int id;
    cout << "Masukkan ID Tas yang ingin diupdate: ";
    cin >> id;
    
    for (int i = 0; i < jumlahTas; i++) {
        if (tas[i].id == id) {
            cout << "Masukkan Nama Tas Baru: ";
            cin.ignore();  // Membersihkan input buffer
            getline(cin, tas[i].nama);
            
            cout << "Masukkan stok Tas Baru: ";
            cin >> tas[i].stok;
            
            cout << "Masukkan Harga Tas Baru: ";
            cin >> tas[i].harga;
            
            cout << "Tas berhasil diupdate!\n";
            return;
        }
    }
    
    cout << "Tas dengan ID tersebut tidak ditemukan.\n";
}

void hapusTas(Tas tas[], int &jumlahTas) {
    int id;
    cout << "Masukkan ID Tas yang ingin dihapus: ";
    cin >> id;
    
    for (int i = 0; i < jumlahTas; i++) {
        if (tas[i].id == id) {
            for (int j = i; j < jumlahTas - 1; j++) {
                tas[j] = tas[j + 1];  
            }
            jumlahTas--;
            cout << "Tas berhasil dihapus!\n";
            return;
        }
    }
    
    cout << "Tas dengan ID tersebut tidak ditemukan.\n";
}

int main() {
    Tas tas[100];
    int jumlahTas = 0;
    int pilihan;
    
    Tas* ptrTas = tas;

    do {
        cout << "\nMenu Pendataan Toko Tas\n";
        cout << "1. Tambah Tas\n";
        cout << "2. Tampilkan Tas\n";
        cout << "3. Update Tas\n";
        cout << "4. Hapus Tas\n";
        cout << "5. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                // Menggunakan pointer untuk menambah tas
                tambahTas(ptrTas, jumlahTas);
                break;
            case 2:
                // Menggunakan pointer untuk menampilkan tas
                tampilkanTas(ptrTas, jumlahTas);
                break;
            case 3:
                // Menggunakan pointer untuk update tas
                updateTas(ptrTas, jumlahTas);
                break;
            case 4:
                // Menggunakan pointer untuk hapus tas
                hapusTas(ptrTas, jumlahTas);
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
