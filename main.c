typedef enum Kualitas {
    Baik,
    Sedang,
    Tidak_Sehat;
} kualitas_udara;

typedef struct Udara {

    float pm10;
    float pm2_5;
    float sulfur_dioksida;
    kualitas_udara kualitas;

} udara;


int main()
{

    return 0;
}
