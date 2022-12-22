#include <stdio.h>
struct chinese{
    int no ;
    char menu [100];
    int harga;
  
} ch ;

int main(){
    FILE * fp ;
    fp = fopen("chinese menu.txt","r");
    printf("selamat datang di menu chinese food\n");
    printf("berikut menu yang tersedia\n");
    
    while((fscanf(fp,"%d %[^.]. %d\n",&ch.no,ch.menu,&ch.harga))!=EOF){
        printf("%d. %s %d\n",ch.no,ch.menu,ch.harga);
    }
    fclose(fp);
}
