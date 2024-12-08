#include <iostream>
#include <iomanip>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <algorithm>
#include <climits>
#include <iomanip>
#define V 10

using namespace std;

struct Produk {
    int id;
    string nama;
    string kategori;
    double harga;
};

unordered_map<int, Produk> produkMap;

string formatRupiah(double harga) {
    stringstream ss;
    ss << "Rp " << fixed << setprecision(0) << harga;
    return ss.str();
}

vector<Produk> daftarProduk = {
    {1, "Smartphone Samsung Galaxy S23", "Elektronik", 12000000},
    {2, "Laptop ASUS ROG Zephyrus G14", "Elektronik", 25000000},
    {3, "TV LED LG 43 Inch", "Elektronik", 6500000},
    {4, "Earbuds Apple AirPods Pro", "Elektronik", 3500000},
    {5, "Kamera DSLR Canon EOS 90D", "Elektronik", 17000000},
    {6, "Sepeda MTB Polygon", "Fitness", 5000000},
    {7, "Dumbbell 5kg", "Fitness", 200000},
    {8, "Matras Yoga", "Fitness", 250000},
    {9, "Mesin Elliptical", "Fitness", 7500000},
    {10, "Resistance Band", "Fitness", 100000},
    {11, "Serum Wajah Vitamin C", "Kecantikan", 150000},
    {12, "Masker Wajah Aloe Vera", "Kecantikan", 75000},
    {13, "Lipstik Matte L'Oréal", "Kecantikan", 120000},
    {14, "Parfum Chanel", "Kecantikan", 2500000},
    {15, "Sabun Cuci Muka Himalaya", "Kecantikan", 35000},
    {16, "Roti Tawar Serba Roti", "Konsumsi", 15000},
    {17, "Kopi Arabica 100g", "Konsumsi", 50000},
    {18, "Mie Instan", "Konsumsi", 5000},
    {19, "Susu UHT Indomilk 1 Liter", "Konsumsi", 18000},
    {20, "Teh Kotak Sosro 500ml", "Konsumsi", 7500}
};

int keranjangBelanja[21] = {0}; 

void tampilkanHeader() {
    cout << "+-----+------------------------------------------+-------------------+----------------+\n";
    cout << "| ID  |                Nama Produk               |     Kategori      |     Harga      |\n";
    cout << "+-----+------------------------------------------+-------------------+----------------+\n";
}

void tampilkanProduk(const vector<Produk>& produk) {
    tampilkanHeader();
    for (const auto& p : produk) {
        cout << "| " << setw(3) << p.id << " | "
             << left << setw(40) << p.nama << " | "
             << left << setw(17) << p.kategori << " | "
             << right << setw(14) << formatRupiah(p.harga) << " |\n";
    }
    cout << "+-----+------------------------------------------+-------------------+----------------+\n";
}

void sortirHarga(vector<Produk>& produk, bool ascending) {
    sort(produk.begin(), produk.end(), [ascending](const Produk& a, const Produk& b) {
        return ascending ? a.harga < b.harga : a.harga > b.harga;
    });
}

vector<Produk> filterKategori(const string& kategori) {
    vector<Produk> hasil;
    for (const auto& p : daftarProduk) {
        if (p.kategori == kategori) {
            hasil.push_back(p);
        }
    }
    return hasil;
}

void tambahKeKeranjang(int idProduk) {
    if (idProduk < 1 || idProduk > 20) {
        cout << "\nProduk dengan ID " << idProduk << " tidak ditemukan.\n";
        return;
    }
    keranjangBelanja[idProduk]++;
    cout << "\nProduk \"" << produkMap[idProduk].nama << "\" berhasil ditambahkan ke keranjang.\n";
}

void tampilkanKeranjang() {
    bool keranjangKosong = true;
    double totalHarga = 0;

    cout << "\nIsi keranjang belanja Anda:\n";
    cout << "+-----+------------------------------------------+------------+----------------+\n";
    cout << "| ID  |                Nama Produk               |   Jumlah   |     Subtotal   |\n";
    cout << "+-----+------------------------------------------+------------+----------------+\n";

    for (int id = 1; id <= 20; ++id) {
        if (keranjangBelanja[id] > 0) {
            keranjangKosong = false;
            double subtotal = keranjangBelanja[id] * produkMap[id].harga;
            totalHarga += subtotal;

            cout << "| " << setw(3) << id << " | "
                 << left << setw(40) << produkMap[id].nama << " | "
                 << setw(10) << keranjangBelanja[id] << " | "
                 << right << setw(14) << formatRupiah(subtotal) << " |\n";
        }
    }

    if (keranjangKosong) {
        cout << "\nKeranjang belanja kosong.\n";
    } else {
        cout << "+-----+------------------------------------------+------------+----------------+\n";
        cout << "Total Harga: " << formatRupiah(totalHarga) << "\n";
    }
}

void hapusDariKeranjang(int idProduk) {
    if (idProduk < 1 || idProduk > 20) {
        cout << "\nProduk dengan ID " << idProduk << " tidak ditemukan.\n";
        return;
    }
    if (keranjangBelanja[idProduk] == 0) {
        cout << "\nProduk \"" << produkMap[idProduk].nama << "\" tidak ada di keranjang.\n";
    } else {
        keranjangBelanja[idProduk]--;
        cout << "\nProduk \"" << produkMap[idProduk].nama << "\" berhasil dihapus dari keranjang.\n";
    }
}

void cariProdukByID() {
    int id;
    cout << "\nMasukkan ID produk yang ingin dicari: ";
    cin >> id;

    if (produkMap.find(id) != produkMap.end()) {
        cout << "\nProduk ditemukan:\n";
        tampilkanProduk({produkMap[id]});
    } else {
        cout << "\nProduk dengan ID " << id << " tidak ditemukan.\n";
    }
}

int minDistance(int dist[], bool sptSet[]) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++) {
        if (!sptSet[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

void dijkstra(int graph[V][V], int src, int dist[], bool sptSet[]) {
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }
    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet);
        sptSet[u] = true;

        for (int v = 0; v < V; v++) {
            if (!sptSet[v] && graph[u][v] != 0 && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
}

void hitungBiayaPengiriman(int dist[], int biayaPerKm) {
    std::cout << "\nBiaya Pengiriman (Per Kilometer Rp " << biayaPerKm << "):\n";
    for (int i = 0; i < V; i++) {
        if (dist[i] == INT_MAX) {
            std::cout << "Ke vertex " << i << ": Tidak dapat dijangkau\n";
        } else {
            int biaya = dist[i] * biayaPerKm;
            std::cout << "Ke vertex " << i << ": " << dist[i] << " km, Biaya: Rp " << biaya << "\n";
        }
    }
}

void menuPengiriman(int graph[V][V]) {
    int pilihan, tujuan;
    int dist[V];
    bool sptSet[V];

    do {
        std::cout << "\n=== MENU PENGIRIMAN ===\n";
        std::cout << "1. Hitung Biaya Pengiriman\n";
        std::cout << "2. Kembali ke Menu Utama\n";
        std::cout << "Pilih opsi (1-2): ";
        std::cin >> pilihan;

        switch (pilihan) {
            case 1:
                std::cout << "Masukkan titik tujuan (0-9): ";
                std::cin >> tujuan;

                dijkstra(graph, 0, dist, sptSet);

                if (dist[tujuan] == INT_MAX) {
                    std::cout << "Titik tujuan tidak dapat dijangkau.\n";
                } else {
                    int biaya = dist[tujuan] * 3000;
                    std::cout << "Jarak terpendek dari 0 ke " << tujuan << ": " << dist[tujuan] << " km\n";
                    std::cout << "Biaya Pengiriman: Rp " << biaya << "\n";
                }
                break;

            case 2:
                std::cout << "Kembali ke Menu Utama.\n";
                break;

            default:
                std::cout << "Pilihan tidak valid. Silakan coba lagi.\n";
        }
    } while (pilihan != 2);
}

    int graph[V][V] = {
        {0, 0, 7, 4, 0, 0, 4, 0, 5, 0}, 
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
        {0, 5, 0, 0, 0, 0, 0, 0, 0, 0}, 
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
        {0, 0, 0, 0, 0, 0, 0, 7, 0, 0},
        {0, 0, 0, 0, 9, 0, 0, 8, 0, 3},
        {0, 4, 0, 0, 2, 11, 0, 0, 0, 0}, 
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 10, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 4, 0, 0}
    };

void menu() {
    int pilihan;
    do {
        cout << "\n=== SELAMAT DATANG DI TOKO TIGASETENGAH! ===\n";
        cout << "1. Tampilkan Semua Produk\n";
        cout << "2. Sortir Produk Berdasarkan Harga\n";
        cout << "3. Filter Produk Berdasarkan Kategori\n";
        cout << "4. Tambahkan Produk ke Keranjang\n";
        cout << "5. Tampilkan Keranjang Belanja\n";
        cout << "6. Cari Produk Berdasarkan ID\n";
        cout << "7. Hapus Produk dari Keranjang\n";
        cout << "8. Hitung Biaya Pengiriman\n";
        cout << "9. Keluar\n";
        cout << "Pilih opsi (1-9): ";
        cin >> pilihan;

        switch (pilihan) {
        case 1:
            cout << "\nDaftar Produk yang Tersedia di Toko TIGASETENGAH:\n";
            tampilkanProduk(daftarProduk);
            break;
        case 2: {
            int urut;
            cout << "\nPilih urutan harga:\n";
            cout << "1. Termurah ke Termahal\n";
            cout << "2. Termahal ke Termurah\n";
            cout << "Pilih opsi (1-2): ";
            cin >> urut;
            sortirHarga(daftarProduk, urut == 1);
            cout << "\nDaftar Produk Setelah Disortir:\n";
            tampilkanProduk(daftarProduk);
            break;
        }
        case 3: {
            string kategori;
            cout << "\nMasukkan kategori (Elektronik, Fitness, Kecantikan, Konsumsi, dll.): ";
            cin >> kategori;
            vector<Produk> hasil = filterKategori(kategori);
            if (hasil.empty()) {
                cout << "\nTidak ada produk dalam kategori \"" << kategori << "\".\n";
            } else {
                cout << "\nDaftar Produk Kategori \"" << kategori << "\":\n";
                tampilkanProduk(hasil);
            }
            break;
        }
        case 4: {
            int idProduk;
            cout << "\nMasukkan ID produk untuk ditambahkan ke keranjang: ";
            cin >> idProduk;
            tambahKeKeranjang(idProduk);
            break;
        }
        case 5:
            tampilkanKeranjang();
            break;

        case 6:
            cariProdukByID();
            break;
        case 7: {
            int idProduk;
            cout << "\nMasukkan ID produk untuk dihapus dari keranjang: ";
            cin >> idProduk;
            hapusDariKeranjang(idProduk);
            break;
        }
        case 8: 
            menuPengiriman(graph);
            break;
        case 9:
            cout << "\nTerima kasih telah berbelanja di Toko TIGASETENGAH. Sampai jumpa lagi!\n";
            break;
        default:
            cout << "\nPilihan tidak valid. Silakan coba lagi.\n";
        }
    } while (pilihan != 9);
}

int main() {
    for (const auto& p : daftarProduk) {
        produkMap[p.id] = p;
    }
    menu();
    return 0;
}