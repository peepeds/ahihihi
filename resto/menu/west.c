#include <stdio.h>
struct west{
    int no ;
    char menu [100];
    int harga;
  
} w ;

int main(){
    FILE * fp ;
    fp = fopen("west menu.txt","r");
    printf("selamat datang di menu western food\n");
    printf("berikut menu yang tersedia\n");
    
    while((fscanf(fp,"%d %[^.]. %d\n",&w.no,w.menu,&w.harga))!=EOF){
        printf("%d. %s %d\n",w.no,w.menu,w.harga);
    }
    fclose(fp);
}
