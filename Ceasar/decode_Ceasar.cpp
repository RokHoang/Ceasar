#include	<stdio.h>
#include	"de_ceasar.h"
char	deconvert(char a,int key)
{
	if ((a>='A') && (a<='Z'))
		return ((a-'A'+26-key)%26)+'a';
	return a;
}
void	deCeasar(int key)
{
	char letter;
	FILE *fo=fopen("PLAIN_TEXT.TXT","a");
	FILE *fi=fopen("CIPHER_TEXT.TXT","rt");
	letter=fgetc(fi);
	while (!feof(fi))
	{	
		fputc(deconvert(letter,key),fo);
		letter=fgetc(fi);
	}
	fprintf(fo,"\n");
	fclose(fi);
	fclose(fo);
}
void	showDecode()
{
	int i;
	FILE *f=fopen("PLAIN_TEXT.TXT","wt");
	fclose(f);
	for (i=1;i<=26;i++)
		deCeasar(i);
}