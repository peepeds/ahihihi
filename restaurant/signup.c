#include <stdio.h>
#include <string.h>

int main(){

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
	fprintf(fp,"%s %s",email , password);
	fclose(fp);

}
