#include <stdio.h>

#define kelompok bebas
#define bebas  3
#define phi 3.14
#define min 0.1
#define cetak(luas){\
    printf("Luas lingkaran "); \
    printf("adalah %.2lf \n", luas); \
}

int main(){
    double jari , i;
    double luas ;
   
    printf("Tugas ini dikerjakan secara berkelompok, nama kelompok kami adalah bebas ,bebas terdiri atas %d orang\n",kelompok);
   
    printf("kami akan mengerjakan tugas berupa menghitung luas lingkaran\n");
    printf("Masukkan jari - jari lingkaran : ");
    scanf("%lf",&jari);
    if(jari < min){
        printf("tidak valid\n");
    }
    luas = phi * jari * jari ;
    cetak(luas);
    return 0;
}
