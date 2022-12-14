#include <stdio.h>

int main(){
    int statusKawin = 0, anak = 0 , statusPasangan= 1 , pajakGabung = 0 ;
    double pendapatanPasangan = 0 , pendapatan = 0 ;
    double ptkp = 0 , pkp = 0  , total = 0 ;
    double lapis1 = 60, lapis2 = 250,lapis3 = 500, lapis4 = 50000, lapis5 = 0 ;
    double akhir = 0;
    // ptkp adalah pendapatan tidak kena pajak 
    // ptkp ditetapkan sebesar 54 juta rupiah , bila sudah menikah ptkp bertambah 5.4 juta
    // bila laporan pendapatan istri dan suami digabung ptkp bertambah lagi sebesar 54 juta rupiah 
    // bila memiliki anak ptkp akan bertambah untuk masing - masing anak sebesar 5.4 juta ( maks 3)

    puts("status pernikahan");
    puts("1. Menikah");
    puts("2. lajang");
    printf("Masukkan status pernikahan : ");
    do{
        scanf("%d",&statusKawin);
        getchar();
        if(statusKawin > 2 || statusKawin < 1 ){
            printf("Tidak valid mohon isi ulang \n");
            puts("1. Menikah");
            puts("2. lajang");
            printf("Masukkan status pernikahan : ");
        }
    } while (statusKawin != 1 &&  statusKawin!= 2);
    printf("Masukkan pendapatan pertahun (dalam juta rupiah): ");
    scanf("%lf",&pendapatan);
    if(statusKawin == 1 ){
        do{
            if(anak < 0){
                printf("Tidak valid masukkan ulang\n");
            }
            printf("Masukkan jumlah anak : ");
            scanf("%d",&anak);
        } while(anak <0);
        do{ 
            if(statusPasangan > 2 || statusPasangan < 1 ){
                printf("Tidak valid mohon isi ulang \n");
            }
            printf("Apakah pasangamu bekerja ?\n");
            printf("1. Ya\n");
            printf("2. Tidak\n");
            printf(">> ");
            scanf("%d",&statusPasangan);
        }while(statusPasangan != 1 && statusPasangan !=2);
        if(statusPasangan==1){
            do{
                printf("Apakah laporan pajak akan digabung ? \n");
                printf("1. Ya\n");
                printf("2. Tidak\n");
                printf(">> ");
                scanf("%d",&pajakGabung);
            } while(pajakGabung != 1 && pajakGabung != 2);
            if(pajakGabung == 1){
                printf("Masukkan pendapatan istrimu (dalam juta rupiah ) : ");
                scanf("%lf",&pendapatanPasangan);
            }
        }
    }
    if(statusKawin==2){
        ptkp = 54 ;
        pkp = pendapatan - ptkp ;
    } else {
        ptkp = 54 +4.5 ;
        if(anak > 3){
            anak = 3 ; 
            ptkp += anak * 4.5 ;
        }
        if(pajakGabung == 1){
            ptkp += 54 ;
        }
        pkp = pendapatan + pendapatanPasangan - ptkp ;
    }

    printf("berdasarkan ptkp tahun 2022 , pkp mu adalah : %lf juta rupuah \n",pkp);

    total = pkp ;
    // pajak di indonesia merupakan pajak progresif 
    // apabila pendapatan kena pajak <= 60 terkena 5%
    // apabila pendapatan kena pajak <= 250 terkena 15%
    // apabila pendapatan kena pajak <= 500 terkena 25%
    // apabila pendapatan kena pajak <= 5000terkena 30%
    // apabila pendapatan kena pajak <= 5000terkena 35%
    
    if(pkp <=0){
        puts("Kamu terbebas dari pajak");
        return 0 ;
    } else {
        if(total <= 60){
            akhir = total * 5 / 100 ; 
            
        } else if ( total <= 310){
            double Lapis1 = 60 * 5 / 100 ;
            total-= 60;
            double Lapis2 = total * 15 / 100 ;
            akhir = Lapis1 + Lapis2;
            
        } else if ( total <= 810){
            double Lapis1 = (double) 60 * 5 / 100 ;
            double Lapis2 = (double) 250 * 15 / 100 ;
            total -= 310 ;
            double Lapis3 =  (double) total * 25 / 100 ;
            akhir =  Lapis2 + Lapis1 + Lapis3 ;
        } else if ( total <= 5810 ){
            double Lapis1 = (double) 60 * 5 / 100 ;
            double Lapis2 = (double) 250 * 15 / 100 ;
            double Lapis3 = (double) 500 * 25 / 100 ;
            total -=  810 ;
            double Lapis4 = (double) total * 30 / 100 ;
            akhir = Lapis1 + Lapis2 + Lapis3 + Lapis4 ;
        } else  if (total > 5810){
            double Lapis1 = (double) 60 * 5 / 100 ;
            double Lapis2 = (double) 250 * 15 / 100 ;
            double Lapis3 = (double) 500 * 25 / 100 ;
            double Lapis4 = (double) 5000 * 30 / 100 ;
            total-= 5810 ;
            double Lapis5 = (double) total * 35 / 100 ;
            akhir =  Lapis1 + Lapis2 + Lapis3 + Lapis4  + Lapis5;

        }
    }
    if( akhir < 1){
        akhir *= 1000;
        printf("kamu perlu membayar pajak sebesar : %lf  ribu rupiah\n",akhir);
       
    } else if (akhir > 1000){
        akhir /= 1000;
        printf("kamu perlu membayar pajak sebesar : %lf miliar rupiah\n",akhir);
       
    }
    printf("kamu perlu membayar pajak sebesar : %lf juta rupiah\n",akhir);

    
}
