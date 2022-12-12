#include <stdio.h>
// kurs kalkulatoe IDR - USD per 12 Des 2022 08.00 WIB

int main(){
    double usd = 15583;
    double idr = 0.64;
    double pilihan , x ;

    puts("kalkulator kurs");
    puts("Kurs per 12 Des 2022 08.00 WIB ");
    puts("1 USD = 15583 IDR");

    printf("\n");
    puts("1. USD => IDR");
    puts("2. IDR => USD");
    printf("Pilih mode : ");
    scanf("%lf",&pilihan);

    if(pilihan == 1){
        printf("Masukkan jumlah USD : ");
        scanf("%lf",&x);
        printf("Nilai USD mu dalam IDR adalah : %.0lf\n",usd*x);
    } else if (pilihan == 2){
        printf("Masukkan jumlah IDR : ");
        scanf("%lf",&x);
        printf("Nilai IDR mu dalam USD adalah : %lf\n",x/usd);
    }
    
}
