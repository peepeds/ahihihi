#include <stdio.h>

 typedef unsigned  panjang ;
 struct voucherKonser {
    struct identitas{
        char nama [50] ;
        panjang  NIK ; 
        char jenisKelamin ;
    } id ;
    char type[25];
    int day ;
} bp[5];

int main(){
    int i = 0;
    int x;
    int y;
    typedef struct {
        char negara [19] ;
        char kota [14];
        char tempat [23]; 
        char tanggal [30];
    } loc;

    loc loc1 = {"Indonesia","Jakarta","Main Hall GBK","5 DES 2023"};
    loc loc2 = {"Indonesia","Jakarta","Main Hall GBK","6 DES 2023"};
    
    do{
        x = i + 1;
        y = x;
        struct  voucherKonser x ;

        printf("Masukkan Nama : ");
        scanf("%[^\n]",bp[i].id.nama);
        getchar();
        printf("Masukkan NIK : ");
        scanf("%u",&bp[i].id.NIK);
        getchar();
        printf("Masukkan Jenis Kelamin (L/P) : ");
        scanf("%c",&bp[i].id.jenisKelamin);
        getchar();
        printf("Pilih Kategori tiket konser :  ");
        scanf("%s",bp[i].type);
        getchar();
        printf("Pilih hari dimana kamu akan menghadiri konser : ");
        scanf("%d",&bp[i].day);
        getchar();
       
        printf("\n-----------------------------\n");

        printf("Tanda terima voucher : %d\n",y);
        
        printf("Voucher ini dimiliki oleh : %s\n",bp[i].id.nama);
        printf("Kategori vouchermu adalah : %s hari ke - %d\n",bp[i].type ,bp[i].day);
        printf("Pastikan kamu membawa KTP , hal ini digunakan untuk menyocokan nama dengan ID KTP\n");
        printf("\n");

        printf("Konser ini bertempat di :\n");
        printf("\n");
        printf("    Negara  : %s\n",loc1.negara);
        printf("    Kota    : %s\n",loc1.kota);
        printf("    Tempat  : %s\n",loc1.tempat);
        if(bp[i].day == 1){
            printf("    Tanggal : %s\n",loc1.tanggal);
        } else {
            printf("    Tanggal : %s\n",loc2.tanggal);
        }
       
        printf("\n");

        printf("TIKET KONSER INI TIDAK BISA DIALIHTANGANKAN DENGAN ALASAN APAPUN\n");
        printf("\n");
        i++;
    } while ( i < 5 );
}
