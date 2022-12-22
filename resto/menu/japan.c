#include <stdio.h>
struct japan{
    int no ;
    char menu [100];
    int harga;
  
} j ;

int main(){
    FILE * fp ;
    fp = fopen("japan menu.txt","r");
    printf("selamat datang di menu japanese food\n");
    printf("berikut menu yang tersedia\n");
    
    while((fscanf(fp,"%d %[^.]. %d\n",&j.no,j.menu,&j.harga))!=EOF){
        printf("%d. %s %d\n",j.no,j.menu,j.harga);
    }
    fclose(fp);
}
