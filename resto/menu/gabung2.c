#include <stdio.h>

struct west{
    int no ;
    char menu [100];
    int harga;
  
} w ;

struct chinese{
    int no ;
    char menu [100];
    int harga;
  
} ch ;

struct japan{
    int no ;
    char menu [100];
    int harga;
  
} j ;

void west();
void japan();
void chinese();

int main(){
    int pilihan ;
    
    do{
        puts("1) western");
        puts("2) japanese");
        puts("3) chinese");
        puts("0) exit");
        printf(">>");
        scanf("%d",&pilihan);
        switch (pilihan)
        {
        case 1:
            west();
            break;
        
        case 2:
            japan();
            break;

        case 3 :
            chinese();
            break;

        case 0 : 
            return 0 ;
        }
    } while (pilihan != 0);
}
void west(){
    FILE * fp ;
    fp = fopen("west menu.txt","r");
    printf("selamat datang di menu western food\n");
    printf("berikut menu yang tersedia\n\n");
    
    while((fscanf(fp,"%d %[^.]. %d\n",&w.no,w.menu,&w.harga))!=EOF){
        printf("%d. %s %d\n",w.no,w.menu,w.harga);
    }
    printf("\n");
    fclose(fp);
}

void chinese(){
    FILE * fp ;
    fp = fopen("chinese menu.txt","r");
    printf("selamat datang di menu chinese food\n");
    printf("berikut menu yang tersedia\\nn");
    
    while((fscanf(fp,"%d %[^.]. %d\n",&ch.no,ch.menu,&ch.harga))!=EOF){
        printf("%d. %s %d\n",ch.no,ch.menu,ch.harga);
    }
    printf("\n");
    fclose(fp);
}

void japan(){
    FILE * fp ;
    fp = fopen("japan menu.txt","r");
    printf("selamat datang di menu japanese food\n");
    printf("berikut menu yang tersedia\n");
    
    while((fscanf(fp,"%d %[^.]. %d\n",&j.no,j.menu,&j.harga))!=EOF){
        printf("%d. %s %d\n",j.no,j.menu,j.harga);
    }
    printf("\n");
    fclose(fp);
}
