typedef enum Kualitas {
    Baik,
    Sedang,
    Tidak_Sehat;
} kualitas_t;

typedef struct Udara {

    float pm10;
    float pm2_5;
    float sulfur_dioksida;
    kualitas_t kualitas;

} udara_t;


int main()
{

    return 0;
}
