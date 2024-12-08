#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <iomanip>
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

string getCurrentTime() {
    time_t now = time(0);
    tm *localTime = localtime(&now);
    char buffer[100];
    strftime(buffer, sizeof(buffer), "%H:%M:%S pada %d/%m/%Y", localTime);
    return string(buffer);
}

string getFilename(const string& nama) {
    time_t now = time(0);
    tm *localTime = localtime(&now);
    char buffer[50];
    strftime(buffer, sizeof(buffer), "%Y%m%d_%H%M%S", localTime);
    return nama + "_" + buffer + ".txt";
}

void saveReceipt(const string& nama, double amount) {
    string filename = getFilename(nama);
    ofstream file(filename);
    if (file.is_open()) {
        file << "===========================\n";
        file << "       STRUK PEMBAYARAN\n";
        file << "===========================\n";
        file << "Nama Pelanggan: " << nama << endl;
        file << "Jumlah Pembayaran: Rp" << fixed << setprecision(2) << amount << endl;
        file << "Waktu Pembayaran: " << getCurrentTime() << endl;
        file << "===========================\n";
        file << "   Terima kasih telah\n";
        file << "   berbelanja di Toko (GO GURL)!\n";
        file << "===========================\n";
        file.close();
        cout << "Struk pembayaran berhasil disimpan sebagai '" << filename << "'\n";
    } else {
        cout << "Gagal menyimpan struk pembayaran.\n";
    }
}

void paymentMenu(const string& nama) {
    double amount;
    cout << "=== Menu Pembayaran ===\n";
    cout << "Pembayaran atas nama: " << nama << endl;
    cout << "Masukkan jumlah pembayaran: ";
    cin >> amount;

    cout << "\nMemproses pembayaran...\n";
    cout << "Pembayaran untuk " << nama << " sebesar Rp" << fixed << setprecision(2) << amount
         << " berhasil.\n";
    cout << "Waktu Pembayaran: " << getCurrentTime() << endl;

    saveReceipt(nama, amount);
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
        cout << endl;

        switch (pilihan) {
            case 1:
                cout << "-> Anda memilih 'Pilih kategori belanja'.\n   (Fitur masih dalam pengembangan)" << endl;
                break;
            case 2:
                cout << "-> Anda memilih 'List belanja'.\n   (Fitur masih dalam pengembangan)" << endl;
                break;
            case 3:
                paymentMenu(nama);
                break;
            case 0:
                cout << "-> Terima kasih telah berbelanja di Toko (GO GURL), " << nama << "!" << endl;
                break;
            default:
                cout << "-> Pilihan tidak valid. Silakan coba lagi!" << endl;
        }
        cout << endl;
    } while (pilihan != 0);

    printFarewell(nama);

    return 0;
}
