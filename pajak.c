#include <stdio.h>

int main(){
    int statusKawin = 0, anak = 0 , statusPasangan= 1  ; // status pasangan di set 1 agar validasi tidak jalan diawal
    int pajakGabung = 0 ;
    double pendapatanPasangan = 0 , pendapatan = 0 ;
    double ptkp = 0 , pkp = 0  , total = 0 ;
    double lapis1 = 60, lapis2 = 250,lapis3 = 500, lapis4 = 50000, lapis5 = 0 ; // dibuat sesuai ketentuan dalam satuan juta 
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
    if(statusKawin == 1 ){ // kalau menikah 
        do{ // skema validasi
            if(anak < 0){
                printf("Tidak valid masukkan ulang\n");
            }
            printf("Masukkan jumlah anak : ");
            scanf("%d",&anak);
        } while(anak <0); // syarat validasi
        do{  // skema validasi 
            if(statusPasangan > 2 || statusPasangan < 1 ){
                printf("Tidak valid mohon isi ulang \n");
            }
            printf("Apakah pasangamu bekerja ?\n");
            printf("1. Ya\n");
            printf("2. Tidak\n");
            printf(">> ");
            scanf("%d",&statusPasangan);
        }while(statusPasangan != 1 && statusPasangan !=2); // syarat validasi 
        if(statusPasangan==1){ // kalau pasangan bekerja 
            do{ // skema validasi 
                printf("Apakah laporan pajak akan digabung ? \n");
                printf("1. Ya\n");
                printf("2. Tidak\n");
                printf(">> ");
                scanf("%d",&pajakGabung);
            } while(pajakGabung != 1 && pajakGabung != 2); // syarat validasi 
            if(pajakGabung == 1){ // kalau laporan pajak  suami dan istri  akan digabung 
                printf("Masukkan pendapatan istrimu (dalam juta rupiah ) : ");
                scanf("%lf",&pendapatanPasangan);
            }
        }
    }
    if(statusKawin==2){ // kalau  masih lajang / tidak menikah 
        ptkp = 54 ;
        pkp = pendapatan - ptkp ;
    } else { // kalau menikah 
        ptkp = 54 + 4.5 ; // 54 adalah ptkp pewajib pajak / orang 
                          // ditambah 4.5 juta , karena bila sudah menikah per keluarga mendapatkan keringanan 4.5 juta 
        if(anak > 3){
            anak = 3 ; // kalau jumlah anak lebih dari 3 , hanya mendapatkan keringanan pajak sebesar 3 anak 
            ptkp += anak * 4.5 ; // masing - masing anak mendapatkan keringanan 4.5 juta 
        } else if (anak <= 3 ){ // selain itu masing - masing anak mendapatkan keringanan 4.5 juta 
            anak = anak ;
            ptkp += anak * 4.5 ;
        }
        if(pajakGabung == 1){
            ptkp += 54 ; // kalau laporan pajak digabung , artinya sebenarnya ada 2 pewajib pajak 
                        // karena digabung maka ptkp  suami dan istri juga digabung , sehingga ditambah 54 juta lagi
        }
        pkp = pendapatan + pendapatanPasangan - ptkp ; // pendapatan pajaknya berarti
                                                       // pendapatan suami / istri + pendapatan pasangan - ptkp 
    }

    printf("berdasarkan ptkp tahun 2022 , pkp mu adalah : %lf juta rupuah \n",pkp);

    total = pkp ;
    // pajak di indonesia merupakan pajak progresif 
    // apabila pendapatan kena pajak <= 60 terkena 5% 
    // apabila pendapatan kena pajak <= 250 terkena 15%
    // apabila pendapatan kena pajak <= 500 terkena 25%
    // apabila pendapatan kena pajak <= 5000terkena 30%
    // apabila pendapatan kena pajak <= 5000terkena 35%
    /*
    contoh kasus  = pkp tono adalah 310 juta rupiah , bentuk penyelesaiannya adalah 
                    60 juta pertama terkena 5 % pajak = maka terkena 3 juta 
                    250 juta kedua terkena 15 % pajak = maka terkena 37.5 juta 
                    total = 3 + 37.5 , maka terkena 40.5 juta rupiah 
    */
    
    if(pkp <=0){ // kalau pkp 0 atau kurang berarti tidak membayar pajak
        puts("Kamu terbebas dari pajak"); 
        return 0 ; // agar program berhenti 
    } else {
        if(total <= 60){ // kalau pkp sampai 60 juta 
            akhir = total * 5 / 100 ; 
            
        } else if ( total <= 310){ // kalau pkp sampai 310 juta 
            double Lapis1 = 60 * 5 / 100 ;
            total-= 60;
            double Lapis2 = total * 15 / 100 ;
            akhir = Lapis1 + Lapis2;
            
        } else if ( total <= 810){ // kalau pkp sampai 810 juta 
            double Lapis1 = (double) 60 * 5 / 100 ;
            double Lapis2 = (double) 250 * 15 / 100 ;
            total -= 310 ;
            double Lapis3 =  (double) total * 25 / 100 ;
            akhir =  Lapis2 + Lapis1 + Lapis3 ;
        } else if ( total <= 5810 ){ // kalau pkp sampai 5 miliar 810 juta 
            double Lapis1 = (double) 60 * 5 / 100 ;
            double Lapis2 = (double) 250 * 15 / 100 ;
            double Lapis3 = (double) 500 * 25 / 100 ;
            total -=  810 ;
            double Lapis4 = (double) total * 30 / 100 ;
            akhir = Lapis1 + Lapis2 + Lapis3 + Lapis4 ;
        } else  if (total > 5810){ / // kalau pkp s diatas 5 miliar 810 juta 
            double Lapis1 = (double) 60 * 5 / 100 ;
            double Lapis2 = (double) 250 * 15 / 100 ;
            double Lapis3 = (double) 500 * 25 / 100 ;
            double Lapis4 = (double) 5000 * 30 / 100 ;
            total-= 5810 ;
            double Lapis5 = (double) total * 35 / 100 ;
            akhir =  Lapis1 + Lapis2 + Lapis3 + Lapis4  + Lapis5;

        }
    }
    if( akhir < 1){ // kalau pajak  dibawah satu juta 
        akhir *= 1000;
        printf("kamu perlu membayar pajak sebesar : %lf  ribu rupiah\n",akhir);
        return 0 ; // agar program berhenti 
       
    } else if (akhir > 1000){ // kalau pajak diatas 1000 juta , 1000 juta = 1 miliar 
        akhir /= 1000;
        printf("kamu perlu membayar pajak sebesar : %lf miliar rupiah\n",akhir);
        return 0 ;  // agar program berhenti 
       
    }
    printf("kamu perlu membayar pajak sebesar : %lf juta rupiah\n",akhir);

}

/*
skema pembagian tugas 
Efren & cio line 14 - 60 / user input & validation 

Efren lebih ke input 
cio lebih ke validasi , bagian do - while nya 

Putri :
- riset skema pembayaran pajak & code line  62 - 97 
- menentukan skema serta perhitungan  ptkp dan pkp nya 

Edbert : 
-  line 97 kebawah 
- code logic bayar pajak berdasarkan ptkp yang ada

*/
