#include <iostream>
#include <string>
using namespace std;

void printLine(char ch = '=', int length = 50) {
    for (int i = 0; i < length; i++) {
        cout << ch;
    }
    cout << endl;
}

void printHeader() {
    printLine('*', 50);
    cout << "*        SELAMAT DATANG DI TOKO (GO GURL)        *" << endl;
    printLine('*', 50);
    cout << endl;
}

void displayMenu() {
    printLine('-', 50);
    cout << "                  MASUK KE MENU" << endl;
    printLine('-', 50);
    cout << "| 1 | Pilih kategori belanja                  |" << endl;
    cout << "| 2 | List belanja                            |" << endl;
    cout << "| 3 | Pembayaran                              |" << endl;
    cout << "| 0 | Exit                                    |" << endl;
    printLine('-', 50);
}

void printFarewell(const string& nama) {
    int totalWidth = 50;
    int nameLength = nama.length();
    int padding = totalWidth - 2 - 14 - nameLength;
    int leftPadding = padding / 2;
    int rightPadding = padding - leftPadding;

    printLine('*', totalWidth);
    cout << "*" << string(leftPadding, ' ') << "SAMPAI JUMPA, " << nama << string(rightPadding, ' ') << "*" << endl;
    printLine('*', totalWidth);
}

int main() {
    string nama;
    int pilihan;

    printHeader();
    cout << "Masukkan nama Anda: ";
    getline(cin, nama);
    cout << endl;
    cout << "Halo, " << nama << "! Selamat berbelanja di Toko (GO GURL)!" << endl;
    cout << "Apa yang bisa kami bantu hari ini?" << endl;

    do {
        displayMenu();
        cout << "Pilih menu [0-3]: ";
        cin >> pilihan;
        cin.ignore();
        cout << endl;

        switch (pilihan) {
            case 1:
                cout << "-> Anda memilih 'Pilih kategori belanja'.\n   (Fitur masih dalam pengembangan)" << endl;
                break;
            case 2:
                cout << "-> Anda memilih 'List belanja'.\n   (Fitur masih dalam pengembangan)" << endl;
                break;
            case 3:
                cout << "-> Anda memilih 'Pembayaran'.\n   (Fitur masih dalam pengembangan)" << endl;
                break;
            case 0:
                cout << "-> Terima kasih telah berbelanja di Toko GO GURL), " << nama << "!" << endl;
                break;
            default:
                cout << "-> Pilihan tidak valid. Silakan coba lagi!" << endl;
        }
        cout << endl;
    } while (pilihan != 0);

    printFarewell(nama);

    return 0;
}
