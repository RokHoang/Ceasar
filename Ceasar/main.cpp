#include	"en_vigenere.h"
#include	"de_vigenere.h"
#include	"en_ceasar.h"
#include	"de_ceasar.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int main()
{
	int		stt,ketqua;
	int		ask=10;
	int		key;
	do
	{
		char	chuoi[10]={0};
		system("cls");
		printf("********** DO AN 3 - 1412161- 1412186 **********\n");
		printf("**1. Ma hoa Ceasar							**\n");
		printf("**2. Giai ma Ceasar							**\n");
		printf("**3. Giai ma Ceasar khong khoa				**\n");
		printf("**4. Ma hoa Virgene				            **\n");
		printf("**5. Giai ma Virgene				        **\n");

		printf("***************************************\n\n");
		printf("Hay chon chuong trinh ban muon su dung: (1,2,3,4,5)\n");
		scanf("%i",&stt);
		switch(stt)
		{
			case 1: printf("Moi ban nhap khoa:\n"); 
					scanf("%i",&key); 
					enCeasar(key);	break;
			case 2: printf("Moi ban nhap khoa:\n"); 
					scanf("%i",&key); 
					deCeasar(key);	break;
			case 3: showDecode();	break;
			case 4: printf("Moi ban nhap khoa:\n");
					scanf("%s",chuoi);
					enVigenere(chuoi);
					break;
			case 5: printf("Moi ban nhap khoa:\n");
					scanf("%s",chuoi);
					deVigenere(chuoi);
					break;
		}
		printf("\n\n---------------------------------------\n\n");
		fflush(stdin);
		do
		{
		printf("Ban co muon tiep tuc su dung chuong trinh khong ? (y/n) \n");
		ask=getch();
		}	while ((ask!=89) && (ask!=121) && (ask!=78) && (ask!=110));
	}	while ((ask==89) || (ask==121));
	return 0;
}