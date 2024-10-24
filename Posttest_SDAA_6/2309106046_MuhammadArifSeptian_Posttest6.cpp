#include <iostream>
#include <string>

using namespace std;

struct Tas
{
    int id;
    string nama;
    int stok;
    float harga;
    Tas *next;
};

Tas *stack = nullptr;
Tas *queuehead = nullptr;
Tas *queueRear = nullptr;

void pushTas()
{
    Tas *newTas = new Tas;

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

void popTas()
{
    if (stack == nullptr)
    {
        cout << "Stack kosong.\n";
        return;
    }

    Tas *temp = stack;
    stack = stack->next;
    delete temp;

    cout << "Tas berhasil di-pop dari stack.\n";
}

void updateTasStack()
{
    int id;
    cout << "Masukkan ID Tas yang ingin diupdate di Stack: ";
    cin >> id;

    Tas *current = stack;
    while (current != nullptr)
    {
        if (current->id == id)
        {
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

void tampilkanStack()
{
    if (stack == nullptr)
    {
        cout << "Stack kosong.\n";
        return;
    }

    Tas *current = stack;
    cout << "Data dalam Stack:\n";
    while (current != nullptr)
    {
        cout << "ID: " << current->id << "\n";
        cout << "Nama: " << current->nama << "\n";
        cout << "Stok: " << current->stok << "\n";
        cout << "Harga: " << current->harga << "\n";
        current = current->next;
    }
}

void enqueueTas()
{
    Tas *newTas = new Tas;

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

    if (queueRear == nullptr)
    {
        queuehead = queueRear = newTas;
    }
    else
    {
        queueRear->next = newTas;
        queueRear = newTas;
    }

    cout << "Tas berhasil ditambahkan ke queue!\n";
}

void dequeueTas()
{
    if (queuehead == nullptr)
    {
        cout << "Queue kosong.\n";
        return;
    }

    Tas *temp = queuehead;
    queuehead = queuehead->next;

    if (queuehead == nullptr)
    {
        queueRear = nullptr;
    }

    delete temp;
    cout << "Tas berhasil di-dequeue.\n";
}

void updateTasQueue()
{
    int id;
    cout << "Masukkan ID Tas yang ingin diupdate di Queue: ";
    cin >> id;

    Tas *current = queuehead;
    while (current != nullptr)
    {
        if (current->id == id)
        {
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

void tampilkanQueue()
{
    if (queuehead == nullptr)
    {
        cout << "Queue kosong.\n";
        return;
    }

    Tas *current = queuehead;
    cout << "Data dalam Queue:\n";
    while (current != nullptr)
    {
        cout << "ID: " << current->id << "\n";
        cout << "Nama: " << current->nama << "\n";
        cout << "Stok: " << current->stok << "\n";
        cout << "Harga: " << current->harga << "\n";
        current = current->next;
    }
}

int fibonacciSearch(int arr[], int x, int n)
{
    int fibMMm2 = 0;
    int fibMMm1 = 1;
    int fibM = fibMMm2 + fibMMm1;
    while (fibM < n)
    {
        fibMMm2 = fibMMm1;
        fibMMm1 = fibM;
        fibM = fibMMm2 + fibMMm1;
    }

    int offset = -1;

    while (fibM > 1)
    {
        int i = (offset + fibMMm2 < n - 1) ? offset + fibMMm2 : n - 1;

        if (arr[i] < x)
        {
            fibM = fibMMm1;
            fibMMm1 = fibMMm2;
            fibMMm2 = fibM - fibMMm1;
            offset = i;
        }
        else if (arr[i] > x)
        {
            fibM = fibMMm2;
            fibMMm1 = fibMMm1 - fibMMm2;
            fibMMm2 = fibM - fibMMm1;
        }
        else
        {
            return i;
        }
    }

    if (fibMMm1 && arr[offset + 1] == x)
        return offset + 1;

    return -1;
}

int jumpSearch(int arr[], int x, int n)
{
    int step = 3;

    int prev = 0;
    while (arr[(step < n ? step : n) - 1] < x)
    {
        prev = step;
        step += 3;
        if (prev >= n)
            return -1;
    }

    while (arr[prev] < x)
    {
        prev++;
        if (prev == (step < n ? step : n))
            return -1;
    }

    if (arr[prev] == x)
        return prev;

    return -1;
}

void badCharHeuristic(string str, int size, int badchar[256])
{
    for (int i = 0; i < 256; i++)
        badchar[i] = -1;

    for (int i = 0; i < size; i++)
        badchar[(int)str[i]] = i;
}

int boyerMooreSearch(string text, string pattern)
{
    int m = pattern.size();
    int n = text.size();

    int badchar[256];
    badCharHeuristic(pattern, m, badchar);

    int s = 0;
    while (s <= (n - m))
    {
        int j = m - 1;

        while (j >= 0 && pattern[j] == text[s + j])
            j--;

        if (j < 0)
        {
            return s;
            s += (s + m < n) ? m - badchar[text[s + m]] : 1;
        }
        else
        {
            s += (1 > j - badchar[text[s + j]]) ? 1 : j - badchar[text[s + j]];
        }
    }

    return -1;
}

int *createArrayFromStack(int &n)
{
    Tas *current = stack;
    n = 0;

    // Hitung jumlah elemen dalam stack
    while (current != nullptr)
    {
        n++;
        current = current->next;
    }

    if (n == 0)
        return nullptr;

    // Buat array untuk menyimpan ID tas dari stack
    int *arr = new int[n];
    current = stack;
    for (int i = 0; i < n; i++)
    {
        arr[i] = current->id;
        current = current->next;
    }

    return arr;
}

int main()
{
    int pilihan;

    do
    {
        cout << "\nMenu Pendataan Toko Tas Berbasis Stack dan Queue\n";
        cout << "1. Push Tas ke Stack\n";
        cout << "2. Pop Tas dari Stack \n";
        cout << "3. Update Tas di Stack\n";
        cout << "4. Tampilkan Stack\n";
        cout << "5. Enqueue Tas ke Queue\n";
        cout << "6. Dequeue Tas dari Queue\n";
        cout << "7. Update Tas di Queue\n";
        cout << "8. Tampilkan Queue\n";
        cout << "9. Fibonacci Search (ID)\n";
        cout << "10. Jump Search (ID)\n";
        cout << "11. Boyer-Moore Search \n";
        cout << "12. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan)
        {
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
        {
            int cariID, n;
            int *arr = createArrayFromStack(n);
            if (arr == nullptr)
            {
                cout << "Stack kosong. Tidak ada data untuk dicari.\n";
                break;
            }

            cout << "Masukkan ID Tas yang dicari di Stack: ";
            cin >> cariID;
            int idx = fibonacciSearch(arr, cariID, n);
            if (idx != -1)
            {
                cout << "Tas dengan ID " << cariID << " ditemukan pada indeks " << idx << ".\n";
            }
            else
            {
                cout << "Tas dengan ID " << cariID << " tidak ditemukan.\n";
            }
            delete[] arr;
            break;
        }
        case 10:
        {
            int cariID, n;
            int *arr = createArrayFromStack(n);
            if (arr == nullptr)
            {
                cout << "Stack kosong. Tidak ada data untuk dicari.\n";
                break;
            }

            cout << "Masukkan ID Tas yang dicari di Stack: ";
            cin >> cariID;
            int idx = jumpSearch(arr, cariID, n);
            if (idx != -1)
            {
                cout << "Tas dengan ID " << cariID << " ditemukan pada indeks " << idx << "\n";
            }
            else
            {
                cout << "Tas dengan ID " << cariID << " tidak ditemukan.\n";
            }
            delete[] arr;
            break;
        }
        case 11:
        {
            string cariNama;
            cout << "Masukkan Nama Tas yang dicari di Stack: ";
            cin.ignore();
            getline(cin, cariNama);

            Tas *current = stack;
            string dataStack = "";
            while (current != nullptr)
            {
                dataStack += current->nama + " ";
                current = current->next;
            }

            int idx = boyerMooreSearch(dataStack, cariNama);
            if (idx != -1)
            {
                cout << "Tas dengan nama " << cariNama << " ditemukan pada indeks " << idx << "\n";
            }
            else
            {
                cout << "Tas dengan nama " << cariNama << "n";
            }
            break;
        }
        case 12:
            cout << "Keluar dari program.\n";
            break;
        default:
            cout << "Pilihan tidak valid.\n";
        }
    } while (pilihan != 12);

    return 0;
}
