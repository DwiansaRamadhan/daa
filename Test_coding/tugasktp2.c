#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


typedef struct {
    int tgl;
    int bln;
    int th;
} Tanggal;

typedef struct {
    char noID[5];
    char nama[30];
    char jenis_kelamin;
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
    scanf("%s", data_ktp.ktp.noID);  
     
    if (strlen(data_ktp.ktp.noID) != 4) {
        printf("Nomor ID harus terdiri dari 4 digit.\n");
        return;
    }
    
    printf("Nama (maks 30 karakter): ");
    scanf("%s[^\n]", data_ktp.ktp.nama); 
    while(getchar() != '\n');

    // validasi input nama
    int i, len;
    len = strlen(data_ktp.ktp.nama);
    for (i = 0; i < len; i++) {
        if (!isalpha(data_ktp.ktp.nama[i])) {
            printf("Nama hanya boleh terdiri dari huruf alfabet.\n");
            return;
        }
    }

    if (len > 30) {
        printf("Nama tidak boleh lebih dari 30 karakter.\n");
        return;
    }
    
    char jenis_kelamin_input;
    do {
        printf("Jenis Kelamin (L/P): ");
        scanf(" %c", &jenis_kelamin_input);
        jenis_kelamin_input = toupper(jenis_kelamin_input), tolower(jenis_kelamin_input);
    } while (jenis_kelamin_input != 'L' && jenis_kelamin_input != 'P');

    data_ktp.ktp.jenis_kelamin = jenis_kelamin_input;

    int tanggal_input, bulan_input, tahun_input;
        printf("Tanggal Lahir (dd mm yyyy): ");
        scanf("%d %d %d", &tanggal_input, &bulan_input, &tahun_input);
        if (tanggal_input < 1 || tanggal_input > 31 || bulan_input < 1 || bulan_input > 12 || tahun_input < 1900 || tahun_input > 2023){
            printf("Format tanggal salah, silakan coba lagi.\n");
            return;
        }
            
    data_ktp.ktp.t.tgl = tanggal_input;
    data_ktp.ktp.t.bln = bulan_input;
    data_ktp.ktp.t.th = tahun_input;

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

int is_valid_date(int day, int month, int year) {
    if (day < 1 || day > 31 || month < 1 || month > 12 || year < 1900 || year > 2023) {
        return 0;
    }
    return 1;
}

void edit_data() {
    char noID[5];
    int i, found = 0;

    printf("\nEdit data KTP\n");
    printf("Masukkan nomor ID: ");
    scanf("%s", noID);

    for (i = 0; i < data_ktp.jml; i++) {
        if (strcmp(noID, (p+i)->ktp.noID) == 0) {
            printf("Data dengan nomor ID %s ditemukan.\n", noID);
            printf("Masukkan data baru:\n");
            printf("Nama (maks 30 karakter): ");
            scanf(" %29[^\n]", (p+i)->ktp.nama);
            while(getchar() != '\n');
            printf("Jenis Kelamin (L/P): ");
            scanf(" %c", &(p+i)->ktp.jenis_kelamin);
            while(getchar() != '\n');
            if (!((p+i)->ktp.jenis_kelamin == 'L' || (p+i)->ktp.jenis_kelamin == 'P')) {
                printf("Jenis kelamin harus diisi L atau P.\n");
                return;
            }
            printf("Tanggal Lahir (dd mm yyyy): ");
            scanf("%d %d %d", &(p+i)->ktp.t.tgl, &(p+i)->ktp.t.bln, &(p+i)->ktp.t.th);
            if (!is_valid_date((p+i)->ktp.t.tgl, (p+i)->ktp.t.bln, (p+i)->ktp.t.th)) {
                printf("Tanggal lahir tidak valid.\n");
                return;
            }
            printf("Data berhasil diubah!\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Data dengan nomor ID %s tidak ditemukan.\n", noID);
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
        printf("4. Edit data\n");
        printf("5. Hapus Data\n");
        printf("6. Keluar\n");
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
                edit_data();
                break;
            case 5:
                hapus_data();
            case 6:
                printf("\nTerima kasih telah menggunakan aplikasi ini!\n");
                break;
            default:
                printf("\nPilihan tidak tersedia, silahkan coba lagi!\n");
                break;
        }
    } while (menu != 6);

    return 0;
}



