#include	<stdio.h>
#include	"en_ceasar.h"
char	convert(char a,int key)
{
	if ((a>='a') && (a<='z'))
		return ((a-'a'+key)%26)+'A';
	return a;
}
void	enCeasar(int key)
{
	char letter;
	FILE *fi=fopen("PLAIN_TEXT.TXT","rt");
	FILE *fo=fopen("CIPHER_TEXT.TXT","wt");
	letter=fgetc(fi);
	while (!feof(fi))
	{	
		fputc(convert(letter,key),fo);
		letter=fgetc(fi);
	}
	fclose(fi);
	fclose(fo);
}