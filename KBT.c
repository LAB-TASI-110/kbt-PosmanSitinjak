#include <stdio.h>
#include <string.h>
#include <stdlib.h> // Untuk exit()

int main() {
    // Variabel untuk menyimpan pilihan dan data tiket
    int pilihanKelas, pilihanRute, noBangku;
    char tanggalTiket[15]; // Cukup untuk format DD-MM-YYYY\0
    long hargaTiket = 0;
    char kelasDipilih[20];
    char ruteDipilih[50];

    // Data rute dan harga (disimpan dalam array paralel untuk kesederhanaan sesuai instruksi "satu fungsi main")
    char *ruteOptions[] = {
        "Medan - Laguboti",
        "Medan - P. Siantar",
        "Medan - Sibolga"
    };
    long hargaEkonomi[] = {90000, 70000, 100000};
    long hargaExecutive[] = {140000, 120000, 150000};
    int jumlahRute = sizeof(ruteOptions) / sizeof(ruteOptions[0]);

    printf("===========================================\n");
    printf("     Selamat Datang di KBT Ticketing System\n");
    printf("===========================================\n");

    // 1. Pilih Kelas
    printf("\nPilih Kelas:\n");
    printf("1. Ekonomi\n");
    printf("2. Executive\n");
    printf("Masukkan pilihan Anda (1/2): ");
    scanf("%d", &pilihanKelas);

    // Validasi pilihan kelas
    while (pilihanKelas < 1 || pilihanKelas > 2) {
        printf("Pilihan tidak valid. Mohon masukkan 1 atau 2: ");
        scanf("%d", &pilihanKelas);
    }

    if (pilihanKelas == 1) {
        strcpy(kelasDipilih, "Ekonomi");
    } else {
        strcpy(kelasDipilih, "Executive");
    }

    // 2. Pilih Rute
    printf("\nPilihan Rute untuk Kelas %s:\n", kelasDipilih);
    for (int i = 0; i < jumlahRute; i++) {
        if (pilihanKelas == 1) {
            printf("%d. %s : Rp %ld\n", i + 1, ruteOptions[i], hargaEkonomi[i]);
        } else {
            printf("%d. %s : Rp %ld\n", i + 1, ruteOptions[i], hargaExecutive[i]);
        }
    }
    printf("Masukkan pilihan rute Anda (1-%d): ", jumlahRute);
    scanf("%d", &pilihanRute);

    // Validasi pilihan rute
    while (pilihanRute < 1 || pilihanRute > jumlahRute) {
        printf("Pilihan tidak valid. Mohon masukkan antara 1 dan %d: ", jumlahRute);
        scanf("%d", &pilihanRute);
    }

    // Set harga dan rute berdasarkan pilihan
    strcpy(ruteDipilih, ruteOptions[pilihanRute - 1]);
    if (pilihanKelas == 1) {
        hargaTiket = hargaEkonomi[pilihanRute - 1];
    } else {
        hargaTiket = hargaExecutive[pilihanRute - 1];
    }

    // 3. Masukkan Tanggal
    printf("\nMasukkan Tanggal Berangkat (DD-MM-YYYY): ");
    scanf("%s", tanggalTiket);
    // Tambahkan validasi format tanggal sederhana jika diinginkan (tidak diminta secara spesifik)
    // Contoh: memastikan panjang string, karakter separator

    // 4. Masukkan Nomor Bangku
    int minBangku, maxBangku;
    if (pilihanKelas == 1) { // Ekonomi
        minBangku = 2;
        maxBangku = 11;
    } else { // Executive
        minBangku = 2;
        maxBangku = 15;
    }

    printf("Masukkan Nomor Bangku (Rentang %d - %d untuk kelas %s): ", minBangku, maxBangku, kelasDipilih);
    scanf("%d", &noBangku);

    // Validasi nomor bangku
    while (noBangku < minBangku || noBangku > maxBangku) {
        printf("Nomor bangku tidak valid. Mohon masukkan nomor antara %d dan %d: ", minBangku, maxBangku);
        scanf("%d", &noBangku);
    }

    // 5. Tampilkan Struk Tiket
    printf("\n===========================================\n");
    printf("               STRUK TIKET KBT\n");
    printf("===========================================\n");
    printf("Tanggal       : %s\n", tanggalTiket);
    printf("Kelas         : %s\n", kelasDipilih);
    printf("Rute          : %s\n", ruteDipilih);
    printf("Nomor Bangku  : %d\n", noBangku);
    printf("Harga Tiket   : Rp %ld\n", hargaTiket);
    printf("===========================================\n");
    printf("       Terima kasih telah memilih KBT!\n");
    printf("===========================================\n");

    return 0;
}
