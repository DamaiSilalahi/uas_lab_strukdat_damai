#include <iostream>
#include <climits>

#define V 10  // Jumlah vertex

// Fungsi untuk menemukan vertex dengan jarak minimum yang belum dikunjungi
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

// Fungsi untuk menjalankan algoritma Dijkstra
void dijkstra(int graph[V][V], int src) {
    int dist[V];   // Array untuk menyimpan jarak terpendek dari src
    bool sptSet[V];  // Set untuk melacak vertex yang telah diproses

    // Inisialisasi jarak dari src ke semua vertex lainnya sebagai tak hingga
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }
    dist[src] = 0;  // Jarak dari src ke dirinya sendiri adalah 0

    // Temukan jarak terpendek untuk semua vertex
    for (int count = 0; count < V - 1; count++) {
        // Pilih vertex dengan jarak minimum yang belum diproses
        int u = minDistance(dist, sptSet);

        // Tandai vertex u sebagai diproses
        sptSet[u] = true;

        // Perbarui jarak untuk vertex yang bertetangga dengan u
        for (int v = 0; v < V; v++) {
            if (!sptSet[v] && graph[u][v] != 0 && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Cetak jarak terpendek dari src ke semua vertex
    std::cout << "Vertex\tDistance from Source\n";
    for (int i = 0; i < V; i++) {
        if (dist[i] == INT_MAX) {
            std::cout << i << "\tINF\n";
        } else {
            std::cout << i << "\t" << dist[i] << "\n";
        }
    }
}

int main() {
    // Matriks adjacency yang telah diberikan
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
        {0, 0, 0, 0, 0, 0, 0, 4, 0, 0},
    };

    // Menjalankan Dijkstra dari vertex 0
    dijkstra(graph, 0);

    return 0;
}
