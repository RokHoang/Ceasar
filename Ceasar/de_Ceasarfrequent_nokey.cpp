#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "de_Ceasarfrequent.h"
char chuan[] = "ETAOINSHRDLUCMWFYGPBVKXJQZetaoinshrdlucmwfygpbvkxjqz";
void lietke(char a[],thongke b[],int &soluong )
{
	int dem = 0;
	
	for (int i = 0; i < strlen(chuan); i++)
	{
		for (int j = 0; j < strlen(a); j++)
			if (a[j] == chuan[i])
				dem++;
		if (dem > 0)
		{
			b[soluong].kitu = chuan[i];
			b[soluong].solan = dem;
			soluong++;
		}
		dem = 0;
	}
}
void sort(thongke b[], int soluong)
{
	for (int i = 0; i < soluong - 1; i++)
	{
		for (int j = i + 1; j < soluong; j++)
		{
			if (b[i].solan < b[j].solan)
			{
				thongke c = b[i];
				b[i] = b[j];
				b[j] = c;
			}
		}
	}
}
void decode(char a[], thongke b[],int i, char dichma[])
{
	int key;
	if (islower(b[i].kitu))
		key = b[i].kitu - 'e';
	else
		key = b[i].kitu - 'E';
	for (int j = 0; j < strlen(a); j++)
	{
		if ((a[j] >= 'A') && (a[j] <= 'Z'))
			dichma[j] = 97 + (((a[j] % 65) - key) + 26) % 26;
		else if ((a[j] >= 'a') && (a[j] <= 'z'))
			dichma[j] = 97 + (((a[j] % 97) - key) + 26) % 26;
		else
			dichma[j] = a[j];
	}
}
void deCeasarfrequent()
{
	int soluong=0;
	char a[100000] = { 0 }, a1[100000] = { 0 }, dichma[100000] = { 0 };;
	thongke b[26] = { 0 };
	FILE *fr = fopen("CIPHER_TEXT.txt", "rt");
	FILE *fw = fopen("DECODE_TEXT.txt", "wt");
	fgets(a, 100000, fr);
	printf("%s", a);
	lietke(a,b,soluong);
	sort(b, soluong);
	for (int i = 0; i < soluong; i++)
	{
		decode(a, b, i, dichma);
		fputs(dichma, fw);
		fprintf(fw, "\n");
	}
	fclose(fr);
	fclose(fw);
}