#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int tgl;
    int bln;
    int th;
} Tanggal;

typedef struct {
    char noID[5];
    char nama[30];
    char jenis_kelamin; // 'L' atau 'P'
    Tanggal t;
} KTP;

typedef struct {
    KTP ktp;
    int jml;
} Data_KTP;

Data_KTP data_ktp;
Data_KTP *p = NULL;

void tambah_data() {
    printf("\nMasukkan data KTP:\n");
    printf("Nomor ID (4 digit): ");
    scanf("%s", data_ktp.ktp.noID);  // hanya menerima 4 karakter input
  
    if (strlen(data_ktp.ktp.noID) != 4) {
        printf("Nomor ID harus terdiri dari 4 digit.\n");
        return;
    }
    printf("Nama (maks 30 karakter): ");
    scanf("%29[^\n]", data_ktp.ktp.nama);  // hanya menerima 29 karakter input
    while(getchar() != '\n');  // menghapus karakter newline di buffer input
    printf("Jenis Kelamin (L/P): ");
    scanf(" %c", &data_ktp.ktp.jenis_kelamin);
    printf("Tanggal Lahir (dd mm yyyy): ");
    scanf("%d %d %d", &data_ktp.ktp.t.tgl, &data_ktp.ktp.t.bln, &data_ktp.ktp.t.th);
    data_ktp.jml = 1;


    if (p == NULL) {
        p = (Data_KTP*) malloc(sizeof(Data_KTP));
    } else {
        p = (Data_KTP*) realloc(p, (data_ktp.jml) * sizeof(Data_KTP));
    }

    *(p + (data_ktp.jml - 1)) = data_ktp;

    printf("\nData berhasil ditambahkan!\n");
}

void cari_data(){
    int tahun;
    printf("\nMasukkan tahun kelahiran: ");
    scanf("%d", &tahun);

    int count = 0;
    for (int i = 0; i < data_ktp.jml; i++) {
        if ((p + i)->ktp.t.th == tahun) {
            printf("\nData ke-%d:\n", i + 1);
            printf("Nomor ID: %s\n", (p + i)->ktp.noID);
            printf("Nama: %s\n", (p + i)->ktp.nama);
            printf("Jenis Kelamin: %c\n", (p + i)->ktp.jenis_kelamin);
            printf("Tanggal Lahir: %d %d %d\n", (p + i)->ktp.t.tgl, (p + i)->ktp.t.bln, (p + i)->ktp.t.th);
            count++;
        }
    }

    if (count == 0) {
        printf("\nData tidak ditemukan!\n");
    }
}

void tampilkan_data() {
    char jenis;
    printf("\nMasukkan jenis kelamin (L/P): ");
    scanf(" %c", &jenis);

    int count = 0;
    for (int i = 0; i < data_ktp.jml; i++) {
        if ((p + i)->ktp.jenis_kelamin == jenis) {
            printf("\nData ke-%d:\n", i + 1);
            printf("Nomor ID: %s\n", (p + i)->ktp.noID);
            printf("Nama: %s\n", (p + i)->ktp.nama);
            printf("Jenis Kelamin: %c\n", (p + i)->ktp.jenis_kelamin);
            printf("Tanggal Lahir: %d %d %d\n", (p + i)->ktp.t.tgl, (p + i)->ktp.t.bln, (p + i)->ktp.t.th);
            count++;
        }
    }

    if (count == 0) {
        printf("\nData tidak ditemukan!\n");
    }
}

void hapus_data() {
    char noID[5];
    printf("\nMasukkan nomor ID data yang akan dihapus (4 digit): ");
    scanf("%s", noID);

    int count = 0;
    for (int i = 0; i < data_ktp.jml; i++) {
        if (strcmp((p + i)->ktp.noID, noID) == 0) {
            for (int j = i; j < data_ktp.jml - 1; j++) {
                *(p + j) = *(p + j + 1);
            }
            data_ktp.jml--;
            count++;
            break;
        }
    }

    if (count == 1) {
        if (data_ktp.jml == 0) {
            free(p);
            p = NULL;
        } else {
            p = (Data_KTP*) realloc(p, (data_ktp.jml) * sizeof(Data_KTP));
        }
        printf("\nData berhasil dihapus!\n");
    } else {
        printf("\nData tidak ditemukan!\n");
    }
}

int main() {
    int menu = 0;

    do {
        printf("\n-- Aplikasi KTP --\n");
        printf("Menu:\n");
        printf("1. Tambah Data\n");
        printf("2. Cari Data Berdasarkan Tahun Kelahiran\n");
        printf("3. Tampilkan Data Berdasarkan Jenis Kelamin\n");
        printf("4. Hapus Data\n");
        printf("5. Keluar\n");
        printf("Pilihan Anda: ");
        scanf("%d", &menu);

        switch (menu) {
            case 1:
                tambah_data();
                break;
            case 2:
                cari_data();
                break;
            case 3:
                tampilkan_data();
                break;
            case 4:
                hapus_data();
                break;
            case 5:
                printf("\nTerima kasih telah menggunakan aplikasi ini!\n");
                break;
            default:
                printf("\nPilihan tidak tersedia, silahkan coba lagi!\n");
                break;
        }
    } while (menu != 5);

    return 0;
}



