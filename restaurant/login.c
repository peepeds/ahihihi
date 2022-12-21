#include <stdio.h>
#include <string.h>

struct check{
    char email [100];
    char password [100];
    char nama[100];
    long unsigned int hp;
} c ;
int main(){
    FILE *fp;
    char email[100];
    char password[100];
    
    int valid = 0;

    printf("Masukkan e-mail : ");
    scanf("%s",email);
    printf("Masukkan password : ");
    scanf("%s",password);
    fp = fopen("data user.txt","r");

    while((fscanf(fp,"%s %lu %s %s\n",c.nama,&c.hp,c.email,c.password))!= EOF){
        if(strcmp(email,c.email)==0){
            if(strcmp(password,c.password)==0){
                valid = 1 ; 
                printf("Login Succes\n");
                printf("Selamat datang %s\n",c.nama);
                break;
            }
        }
            
    }
    if(valid ==0){
        printf("Login Failed!\n");
   
    }
    fclose(fp);
}

