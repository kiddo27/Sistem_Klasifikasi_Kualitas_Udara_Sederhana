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

//Ubah enum kualitas jadi string
const char* namaKualitas(kualitas_t k){
    switch(k){
        case Baik: return "Baik";
        case Sedang: return "Sedang";
        case Tidak_Sehat: return "Tidak Sehat";
        default: return "-";
    }
}

udara_t inputUdara(){
    udara_t udara;
    printf("Apakah Hari ini Hujan?? (1/0): \n");
    scanf("%d", &udara.isHujan);
    printf("Apakah hari ini angin kencang?? (1/0): \n");
    scanf("%d", &udara.angin_kencang);
    printf("Masukkan Jumlah PM2.5: \n");
    scanf("%f", &udara.pm2_5);
    return udara;
}

udara_t klasifikasiUdara(udara_t dataUdara[], int n){
    
    for(int i=0; i<n; i++){
        if(dataUdara[i].isHujan == 1 || dataUdara[i].angin_kencang == 1){
            dataUdara[i].kualitas = Baik;
            printf("Kualitas Udara Hari ke-%d : %s\n", i+1, namaKualitas(dataUdara[i].kualitas));
        }else{
            if(dataUdara[i].pm2_5 >0 && dataUdara[i].pm2_5 <=50){
                dataUdara[i].kualitas = Baik;
                printf("Kualitas Udara Hari ke-%d : %s\n", i+1, namaKualitas(dataUdara[i].kualitas));
            }else if(dataUdara[i].pm2_5 > 50 && dataUdara[i].pm2_5 <=100){
                dataUdara[i].kualitas = Sedang;
                printf("Kualitas Udara Hari ke-%d : %s\n", i+1, namaKualitas(dataUdara[i].kualitas));
            }else if(dataUdara[i].pm2_5 > 100){
                dataUdara[i].kualitas = Tidak_Sehat;
                printf("Kualitas Udara Hari ke-%d : %s\n", i+1, namaKualitas(dataUdara[i].kualitas));
            }else{
                printf("PM 2.5 Tidak Valid!!! Harus > 0");
            }
        }
    }
}

int main()
{
    printf("=== SISTEM KUALIFIKASI KUALTIAS UDARA ===\n");
    
    int jumlahData;
    printf("\nMasukkan Jumlah Data Harian Udara: ");
    scanf("%d", &jumlahData);

    udara_t *dataUdara;
    dataUdara = (udara_t*)calloc(jumlahData,sizeof(udara_t));

    for(int i=0;i<jumlahData;i++){
        printf("\nMasukkan data udara hari ke-%d\n", i+1);
        dataUdara[i] = inputUdara();
    }

    printf("\n=== Report Kualitas Udara ===\n");
    klasifikasiUdara(dataUdara,jumlahData);
    return 0;
}
