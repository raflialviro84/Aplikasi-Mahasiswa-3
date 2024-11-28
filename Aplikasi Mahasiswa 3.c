#include <stdio.h>
#include <string.h>

typedef struct {
    char nama[50];
    char npm[10];
    char prodi[50];
    float ipk;
} Mahasiswa;

void tukar(Mahasiswa *a, Mahasiswa *b) {
    Mahasiswa temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(Mahasiswa arr[], int n, int kriteria, int ascending) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            int kondisi = 0;
            if (ascending == 1) {
                  kondisi = (kriteria == 1 && strcmp(arr[j].nama, arr[j + 1].nama) > 0) ||
                            (kriteria == 2 && strcmp(arr[j].npm, arr[j + 1].npm) > 0) ||
                            (kriteria == 3 && strcmp(arr[j].prodi, arr[j + 1].prodi) > 0) ||
                            (kriteria == 4 && arr[j].ipk > arr[j + 1].ipk);
            } else {
                  kondisi = (kriteria == 1 && strcmp(arr[j].nama, arr[j + 1].nama) < 0) ||
                            (kriteria == 2 && strcmp(arr[j].npm, arr[j + 1].npm) < 0) ||
                            (kriteria == 3 && strcmp(arr[j].prodi, arr[j + 1].prodi) < 0) ||
                            (kriteria == 4 && arr[j].ipk < arr[j + 1].ipk);
            }
            if (kondisi) {
                tukar(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void selectionSort(Mahasiswa arr[], int n, int kriteria, int ascending) {
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            int kondisi = 0;
            if (ascending == 1) {
                kondisi = (kriteria == 1 && strcmp(arr[j].nama, arr[min_idx].nama) < 0) ||
                            (kriteria == 2 && strcmp(arr[j].npm, arr[min_idx].npm) < 0) ||
                            (kriteria == 3 && strcmp(arr[j].prodi, arr[min_idx].prodi) < 0) ||
                            (kriteria == 4 && arr[j].ipk < arr[min_idx].ipk);
            } else {
                kondisi = (kriteria == 1 && strcmp(arr[j].nama, arr[min_idx].nama) > 0) ||
                            (kriteria == 2 && strcmp(arr[j].npm, arr[min_idx].npm) > 0) ||
                            (kriteria == 3 && strcmp(arr[j].prodi, arr[min_idx].prodi) > 0) ||
                            (kriteria == 4 && arr[j].ipk > arr[min_idx].ipk);
            }
            if (kondisi) {
                min_idx = j;
            }
        }
        tukar(&arr[min_idx], &arr[i]);
    }
}

void insertionSort(Mahasiswa arr[], int n, int kriteria, int ascending) {
    int i, j;
    Mahasiswa key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && ((ascending == 1 && ((kriteria == 1 && strcmp(key.nama, arr[j].nama) < 0) ||
                                              (kriteria == 2 && strcmp(key.npm, arr[j].npm) < 0) ||
                                              (kriteria == 3 && strcmp(key.prodi, arr[j].prodi) < 0) ||
                                              (kriteria == 4 && key.ipk < arr[j].ipk))) ||
                          (ascending != 1 && ((kriteria == 1 && strcmp(key.nama, arr[j].nama) > 0) ||
                                              (kriteria == 2 && strcmp(key.npm, arr[j].npm) > 0) ||
                                              (kriteria == 3 && strcmp(key.prodi, arr[j].prodi) > 0) ||
                                              (kriteria == 4 && key.ipk > arr[j].ipk))))) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void printArray(Mahasiswa arr[], int size) {
    int i;

    printf("\n---------------------------------------------------------\n");
    printf("%-20s %-10s %-20s %-5s\n", "Nama", "NPM", "Prodi", "IPK");
    printf("---------------------------------------------------------\n");
    for (i = 0; i < size; i++)
        printf("%-20s %-10s %-20s %-5.2f\n", arr[i].nama, arr[i].npm, arr[i].prodi, arr[i].ipk);
    printf("---------------------------------------------------------\n");
}

int main() {
    Mahasiswa data[10] = {
        {"Arif Choirudin", "061", "Teknik Informatika", 3.5},
        {"Farel Budi", "012", "Sistem Informasi", 3.2},
        {"Fernando Young", "093", "Teknik Elektro", 3.8},
        {"Rafli Alviro", "224", "Teknik Industri", 4},
        {"Reno Alfa Reza", "305", "DKV", 3.7},
        {"Azrul Ananda", "211", "Akuntansi", 2.9},
        {"Sahzada", "767", "Hukum", 3.6},
        {"Dicky Haikal", "268", "Psikologi", 3.9},
        {"David Ainur", "399", "Kedokteran", 3.4},
        {"Salman Alfarizi", "110", "Biologi", 3.3}
    };
    int n = 10;

    printArray(data, n);

    int sortType, kriteria, ascending;

    do {
        printf("\nPilih kriteria pengurutan:\n1. Nama\n2. NPM\n3. Prodi\n4. IPK\nPilih Kriteria: ");
        scanf("%d", &kriteria);
    } while (kriteria < 1 || kriteria > 4);

    do {
        printf("\nPilih urutan:\n1. Ascending (A-Z/0-9)\n2. Descending (Z-A/9-0)\nPilih Urutan: ");
        scanf("%d", &ascending);
    } while (ascending < 1 || ascending > 2);

    do {
        printf("\nPilih metode pengurutan:\n1. Bubble Sort\n2. Selection Sort\n3. Insertion Sort\nPilih Metode: ");
        scanf("%d", &sortType);

        switch (sortType) {
            case 1:
                bubbleSort(data, n, kriteria, ascending);
                break;
            case 2:
                selectionSort(data, n, kriteria, ascending);
                break;
            case 3:
                insertionSort(data, n, kriteria, ascending);
                break;
            default:
                printf("Pilihan tidak valid. Coba Lagi\n");
        }
    } while(sortType < 1 || sortType > 3);

    printf("\nHasil pengurutan:");
    printArray(data, n);
    return 0;
}
