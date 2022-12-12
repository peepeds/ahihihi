#include <stdio.h>

int main(){
    int modal , Return , lama , pertambahan , i = 0 ; 
    int total  = 0 ,x , modaltotal , laba ;
    double ROI = 0 ;

    printf("Masukkan modal kamu saat ini : ");
    scanf("%d",&modal);
    printf("Target investasi pertahun (dalam persen) : ");
    scanf("%d",&Return);
    printf("Jangka waktu investasi (dalam tahun) : ");
    scanf("%d",&lama);
    printf("Jumlah investasi per tahun : ");
    scanf("%d",&pertambahan);
    printf("\n");
    while( i < lama){
        i++;
        if(i==1){
            total =  modal + pertambahan ; 
            total = total + ( total * Return / 100);
            printf("imbal hasil tahun ke - %d : %d\n",i,total);
        } else {
            total = total + pertambahan; 
            total = total + (total * Return / 100);
            printf("imbal hasil tahun ke - %d : %d\n",i,total);
        }
    
    }
    modaltotal = modal + pertambahan * lama; 
    laba = total - modaltotal ;
    ROI = (double)  modaltotal / total * 100;
    ROI = 100 - ROI;

    printf("investasi pokokmu sebesar : %d\n",modaltotal);
    printf("imbal hasil investasimu sebesar : %d\n",laba);
    printf("Return on Investmentmu adalah : %.3lf%%\n",ROI);

}
