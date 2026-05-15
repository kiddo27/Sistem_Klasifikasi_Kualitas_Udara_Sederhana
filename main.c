#include <stdio.h>
#include <stdlib.h>


typedef enum Kualitas {
    Baik,
    Sedang,
    Tidak_Sehat
} kualitas_t;

typedef struct Udara {
    int isHujan;
    int angin_kencang;
    float pm2_5;
    kualitas_t kualitas;
} udara_t;

// enum kualitas -> string
const char* namaKualitas(kualitas_t k)
{
    switch (k) {
        case Baik: return "Baik";
        case Sedang: return "Sedang";
        case Tidak_Sehat: return "Tidak Sehat";
        default: return "-";
    }
}

udara_t inputUdara()
{
    udara_t udara;
    printf("Apakah Hari ini Hujan?? (1/0)         : ");
    scanf("%d", &udara.isHujan);
    printf("Apakah Hari ini Angin Kencang?? (1/0) : ");
    scanf("%d", &udara.angin_kencang);
    printf("Masukkan Jumlah PM2.5                 : ");
    scanf("%f", &udara.pm2_5);
    return udara;
}

udara_t klasifikasiUdara(udara_t dataUdara[], int n)
{
    printf("\n=============================================\n");
    printf("           Report Kualitas Udara\n");
    printf("=============================================\n");
    
    for(int i = 0; i < n; i++) {
        if(dataUdara[i].isHujan == 1 || dataUdara[i].angin_kencang == 1) {
            dataUdara[i].kualitas = Baik;
            printf("Kualitas Udara Hari ke-%d : %s\n", i + 1, namaKualitas(dataUdara[i].kualitas));
        } else {
            if (dataUdara[i].pm2_5 > 0 && dataUdara[i].pm2_5 <= 50) {
                dataUdara[i].kualitas = Baik;
                printf("Kualitas Udara Hari ke-%d : %s\n", i + 1, namaKualitas(dataUdara[i].kualitas));
            } else if (dataUdara[i].pm2_5 > 50 && dataUdara[i].pm2_5 <= 100) {
                dataUdara[i].kualitas = Sedang;
                printf("Kualitas Udara Hari ke-%d : %s\n", i + 1, namaKualitas(dataUdara[i].kualitas));
            } else if (dataUdara[i].pm2_5 > 100) {
                dataUdara[i].kualitas = Tidak_Sehat;
                printf("Kualitas Udara Hari ke-%d : %s\n", i + 1, namaKualitas(dataUdara[i].kualitas));
            } else {
                printf("PM 2.5 Tidak Valid!!! Harus > 0");
            }
        }
    }
}

void MenuAwalInformasi(){
    printf("\n=============== SISTEM KUALIFIKASI KUALTIAS UDARA ===============\n");
    printf("Informasi Program:\nProgram ini menyiapkan 2 fitur berupa pengecekan kualitas udara di \nsuatu daerah dan hitungan mundur sebelum kiamat iklim terjadi.\n");
    printf("=================================================================\n");
    printf("Pilih Menu:\n1. Pengecekan Kualitas Udara\n2. Perhitungan kiamat iklim\n3. Exit\nPilihan: ");
}

void MenuInputUdara(int n){
    printf("=============================================\n");
    printf("Masukkan data udara hari ke-%d\n", n+1);
    printf("=============================================\n");
}
int main()
{
    int pilihan, input;
    int size = 0, capacity = 3; 

    do{
    MenuAwalInformasi();
    scanf("%d", &pilihan);

    switch(pilihan){
        case 1:
            //Inisialisasi Array Dinamis
            udara_t *dataUdara;
            dataUdara = (udara_t*)calloc(capacity,sizeof(udara_t));
            if(dataUdara == NULL){
                printf("Alokasi Memori Gagal");
                free(dataUdara);
                return 1;
            }

            while(1){
            if (input == 0){
                break;
            }

            if (capacity == size){
                capacity *= 2;
                dataUdara = realloc(dataUdara, capacity*sizeof(udara_t));
            }

            //Input Data
            MenuInputUdara(size);
            dataUdara[size] = inputUdara();
            size++;
            printf("Lanjut mengisi? (1/0): ");
            scanf("%d", &input);
            }

            //Output Data
            klasifikasiUdara(dataUdara,size); 
            free(dataUdara);
            break;

        case 2:
        break;
            }
    } while (pilihan != 3);
    
    printf("Terimakasih Telah Menggunakan Program Ini");
    return 0;
}
