#include <stdio.h>
#include <string.h>

struct check{
    char email [100];
    char password [100];
    char nama[100];
    long unsigned int hp;
} c ;

void signup();
void login();
int main(){
    int pilihan = 0;

    do{
        puts("1. sign up");
        puts("2. login ");
        puts("3. exit");
        scanf("%d",&pilihan);
        switch (pilihan){
        case  1: 
            signup();
            break;
        case 2:
            login();
            break;
        
        case 3 :
            return 0 ;
        }
    } while (pilihan != 3);
}

void signup(){
    FILE *fp ;
	char nama[100];
	long unsigned int hp;
	char email [100];
	char password[100]; 
	char validasi[100];
	int len , lenpw , i  ,j ,c=0;
	int critical = 0 , lowercase = 0 , uppercase =0 , number = 0,  check = 0;
	
	printf("Masukkan Nama         : ");
	scanf("%s",nama);getchar();
	printf("Masukkan Nomor HP     : ");
	scanf("%lu",&hp);getchar();
	printf("Masukkan email        : ");
	do{
		scanf("%s",email);getchar();
		len = strlen(email);
		for(i=0;i<len;i++){
			if(email[i]=='@'){
				c++;
			} 
		}
		if(c<1){
			printf("tidak Valid \n");
			printf("Harap Masukkan e-mail ulang \n");
			printf(">> ");
		}
	} while (c < 1);

	printf("Masukkan password     : ");
	do{
		scanf("%[^\n]",password);getchar();
		lenpw = strlen(password);
		if(lenpw < 8){
			goto sini ;
		}
		for(j=0;j<lenpw;j++){
			if(password[j]>= 97 && password[j]<=122){
				lowercase++ ;
			} else if (password[j]>= 97-32 && password[j] <=122-32){
				uppercase++ ;
			} else if(password[j]>= 48 && password[j] <=57){
				number++;
			}

		}
		if(lowercase>=1){
			lowercase = 1;
		}
		if(uppercase>=1){
			uppercase = 1;
		}
		if (number >=1){
			number = 1 ;
		}
		if(len >=1){
			lenpw = 1;
		}
		critical = lowercase + uppercase + number + len ;
		if( critical < 4){
			printf("Password harus terdiri atas  :\n");
			sini :
			printf("1. satu karakter lowercase :\n");
			printf("2. satu karakter uppercase :\n");
			printf("3. satu karakter nomor\n");
			printf("4. memiliki panjang sekurang-kurangnya 8 karakter\n");
			printf("Tidak valid harap masukkan password ulang :\n");
			printf(">> ");
		}
		
	}while ( critical < 4);
	printf("Validasikan password  : ");
	do {
	scanf("%[^\n]",validasi);getchar();
	if(strcmp(password,validasi)==0){
		check++;
	}
	if(check < 1){
		printf("Tidak valid , harus sesuai dengan password diatas !\n");
		printf("Massukan ulang\n");
		printf(">> ");
	}
	} while ( check < 1);
	fp = fopen("data user.txt","a+");
	fprintf(fp,"%s %lu %s %s\n",nama,hp,email,password);
	fclose(fp);
	fp =fopen("Data.txt","a+");
	fprintf(fp,"%s %s\n",email , password);
	fclose(fp);
}

void login(){
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
            } else {
				valid = 2 ;
				printf("Login failed\n");
				printf("Password salah\n");
				break;
			}
        }
            
    }
    if(valid ==0){
        printf("Login Failed!\n");
		printf("Akun tidak tersedia\n");
   
    }
    fclose(fp);
}
